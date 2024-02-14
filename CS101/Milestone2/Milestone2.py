import math as m

def find_splice(dna_motif, dna):
    idx = 0
    arr = [0]
    for pos, letter in enumerate(dna):
        if idx == len(dna_motif):
            return arr[1:]
        if pos < arr[-1]:
            continue
        if letter == dna_motif[idx]:
            arr.append(pos)
            idx += 1
    return []

def partchecker (dna_list,part):            #return true if all dna sequences have the specified part.
    for i in range(1,len(dna_list)):
        if dna_list[i].find(part) == -1:
            return False
    return True
def shared_motif(dna_list): #will find the longest substring by looking at first character in first string and seeing if it exists in the other strings. If true then look at first two characters. Then shift over to the second character.
    longestsub = ""
    for substart in range (0,len(dna_list[0])):      #first character in the first string index to last character in first string index
        for sublength in range (1,len(dna_list[0])-substart+1): #check the substring from "substart" to "substart"+sublength. We will increase sublength by one until we cant find "substart"+sublength in the other dna strings
            part = dna_list[0][substart:substart+sublength]
            if partchecker(dna_list,part) == False:     #made seperate function to check if "part" exists in all the other dna strings
                break
            else:
                if sublength > len(longestsub):
                    longestsub = part
    return(longestsub)

def get_edges(dna_dict):
    ID_array = []
    dna_array = []
    dna_pre = []
    dna_suf = []
    edges = []
    for ID in dna_dict:
        ID_array.append(ID)
    for dna in dna_dict.values():
        dna_array.append(dna)
        dna_pre.append(dna[0:3])
        dna_suf.append(dna[-3:])
    for i in range(len(dna_array)):
        for k in range(len(dna_array)-1):
            suf = ((i+k+1)%len(dna_array))
            if dna_pre[suf] == dna_suf[i]:
                edges.append((ID_array[i],ID_array[suf]))
    return edges

def short_assemble(dna_list):
    dict = {}
    for idx1 in range(len(dna_list)):
        for j in range(len(dna_list)-1):
            idx2 = (idx1+j+1)%len(dna_list)
            term1 = dna_list[idx1]
            term2 = dna_list[idx2]
            if len(term1) < len(term2):
                max = len(term1)
            else:
                max = len(term2)
            for k in range(max):
                suffix = term1[len(term1)-k:len(term1)]
                prefix = term2[0:k]
                if suffix == prefix:
                    overlap = k
            dict[idx1,idx2] = overlap
    return dict
def assemble_best_genome(dna_list):
    dict = short_assemble(dna_list)
    best = max(dict, key=dict.get)
    overlap = dict[best]
    preidx,sufidx = best
    pre = dna_list[preidx]
    suf = dna_list[sufidx]
    final = pre + suf[overlap:len(suf)]
    dna_list.remove(suf)
    dna_list.remove(pre)
    dna_list.append(final)
    return dna_list
def assemble_genome(dna_list):
    new_dna = dna_list
    while len(dna_list) > 1:
        new_dna = assemble_best_genome(new_dna)
    return new_dna[0]

def perfect_match(rna):
    A = rna.count('A')
    G = rna.count('G')
    C = rna.count('C')
    U = rna.count('U')
    if A != U:
        return 0
    if  C != G:
        return 0
    return ((m.factorial(A))*(m.factorial(G)))

def random_genome(dna, gc_content):
    ATcount = dna.count("A") + dna.count("T")   #counts the number of AT and CG amounts in dna
    GCcount = dna.count("G") + dna.count("C")
    problist = []
    for GCcontent in gc_content:    #we want to calculate the prob for each GC_content, so we iterate over it
        GCfreq = GCcontent/2
        ATfreq = .5-GCfreq
        samestringprob = GCfreq**GCcount*ATfreq**ATcount    #take the frequency of getting a G or C and multiply it by itself by the number of times that you have a G or C in your dna. Do the same with A or T
        problist.append(m.log10(samestringprob))        #we want to take log10 of previous value to get values that differ enough in value
    return problist

def reverse_complement(dna):
    dna2= ''
    dna= dna[::-1]
    for n in dna:
        if n=='A':
            dna2 += 'T'
        elif n=='T':
            dna2 += 'A'
        elif n=='C':
            dna2 += 'G'
        elif n== 'G':
            dna2 +='C'
        else:
            continue
    return dna2  #Made by Gage
def rev_palindrome(dna):
    arr = []
    for pos in range(len(dna)):
        for length in range(2,7):
            if dna[pos:pos+length] == reverse_complement(dna[pos+length:pos+length+length]):
                arr.append((pos,length+length))
    return arr