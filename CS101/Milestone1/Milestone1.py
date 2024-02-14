def s(dna):     #function simply searches for all instances of A,C,G,T in the dna string and adds them individually to a dictionary
    dict = {}
    dict["A"] = dna.count("A")
    dict["C"] = dna.count("C")
    dict["G"] = dna.count("G")
    dict["T"] = dna.count("T")
    return dict  #Made by Mark

def dna2rna(dna):
    rna= ''
    for n in dna:
        if n=='T':
            rna+= 'U'
        else:
            rna+= n
    return rna

def reverse_complement(dna):
    dna2= ''
    dna= dna[::-1]
    for n in dna:
        if n=='A':
            dna2+= 'T'
        elif n=='T':
            dna2+= 'A'
        elif n=='C':
            dna2+= 'G'
        elif n== 'G':
            dna2+='C'
        else:
            continue
    return dna2

def pair_maker(hom,het,rec): #makes list of all allele pairs
    allele_pair_list = []
    for a in range(hom):
        allele_pair_list.append("AA")
    for b in range(het):
        allele_pair_list.append("Aa")
    for c in range(rec):
        allele_pair_list.append("aa")
    return allele_pair_list  #Made by Mark
def mendels_law(hom,het,rec):
    Dprob = 0                                       #function calculates the average probability of two randomly selected allele pairs in population to express dominant trait
    Dprob_instances = 0                             #will accomplish this by averaging the probability of each type of pairng producing a dominant trait
    pairlist = pair_maker(hom,het,rec)
    for indx in range(len(pairlist)):             # go from the first pair (a type of pair could be AA,Aa, or aa) in list to the second last
        for ndx in range(indx+1,len(pairlist)):
            if pairlist[indx] == "AA":                              # any AA pair will produce only homozygous recessive pairs.
                Dprob += 1
                Dprob_instances += 1
            elif pairlist[indx] == "Aa" and pairlist[ndx] == "Aa":    #if both pairs are Aa
                Dprob += .75                                        #probability of dominant allele pair is 75%. add this to Dprob
                Dprob_instances += 1                                #take number of times Dprob was added to later take average
            elif pairlist[indx] == "Aa" and pairlist[ndx] == "aa":    #if you cross Aa with aa
                Dprob += .50                                        #half will half dominant allele
                Dprob_instances += 1
            elif pairlist[indx] == "aa" and pairlist[ndx] == "Aa":    #pairing aa with Aa (order matters since we check each pairing going right only)
                Dprob += .50
                Dprob_instances += 1
            elif pairlist[indx] == "aa" and pairlist[ndx] == "aa":   #aa pair with aa
                Dprob += 0
                Dprob_instances += 1
            elif pairlist[indx] == "Aa" and pairlist[ndx] == "AA":   #100% chance, same situtation as our first if statement
                Dprob += 1
                Dprob_instances += 1
            elif pairlist[indx] == "aa" and pairlist[ndx] == "AA":   #100%, same situation as previous if statement
                Dprob += 1
                Dprob_instances += 1
    average_Dprob = Dprob/Dprob_instances
    return average_Dprob  #Made by Mark

def fibonacci_rabbits(n,k):
    baby=1
    adult=0
    index=0
    while index<n:
        total=baby+adult
        baby=adult*k
        adult=total
        index+=1
    return total  #Made by Zach

def GC_content(dna_list):
    highest_string_index = 0
    highest_GC_count_percent = 0
    for string in dna_list:
        index = dna_list.index(string)
        GCtotpercent = (dna_list[index].count("G") + dna_list[index].count("C"))/len(dna_list[index])*100
        if GCtotpercent > highest_GC_count_percent:
            highest_string_index = index
            highest_GC_count_percent = GCtotpercent
    return highest_string_index,highest_GC_count_percent  #Made by Mark

def rna2codon(rna):
    rna = rna.upper()
    amino= ''
    codons= {'UUU': 'F',      'CUU': 'L',      'AUU': 'I',      'GUU': 'V',
'UUC': 'F',      'CUC': 'L',      'AUC': 'I',      'GUC': 'V',
'UUA': 'L',      'CUA': 'L',      'AUA': 'I',      'GUA': 'V',
'UUG': 'L',      'CUG': 'L',      'AUG': 'M',      'GUG': 'V',
'UCU': 'S',      'CCU': 'P',      'ACU': 'T',      'GCU': 'A',
'UCC': 'S',      'CCC': 'P',      'ACC': 'T',      'GCC': 'A',
'UCA': 'S',      'CCA': 'P',      'ACA': 'T',      'GCA': 'A',
'UCG': 'S',      'CCG': 'P',      'ACG': 'T',      'GCG': 'A',
'UAU': 'Y',      'CAU': 'H',      'AAU': 'N',      'GAU': 'D',
'UAC': 'Y',      'CAC': 'H',      'AAC': 'N',      'GAC': 'D',
'---': '' ,      'CAA': 'Q',      'AAA': 'K',      'GAA': 'E',
'---': '' ,      'CAG': 'Q',      'AAG': 'K',      'GAG': 'E',
'UGU': 'C',      'CGU': 'R',      'AGU': 'S',      'GGU': 'G',
'UGC': 'C',      'CGC': 'R',      'AGC': 'S',      'GGC': 'G',
'---': '' ,      'CGA': 'R',      'AGA': 'R',      'GGA': 'G',
'UGG': 'W',      'CGG': 'R',      'AGG': 'R',      'GGG': 'G' }
    for n in range(0,int(len(rna)/3)):
        triplet= rna[3*n:3*n+3]         #Triplet= every 3 letters in rna
        if triplet in codons:
            amino+= codons[triplet]
        else:
            return amino
    return amino

def locate_substring(dna_snippet,dna):
    final = []
    current = 0
    for i in range(0,len(dna)-len(dna_snippet)):
        current = dna[i:i+len(dna_snippet)]
        if current == dna_snippet:
            final.append(i)
    return final  #Made by Zach

def hamming_dist(dna1, dna2):
    total = 0
    for i in range(0,len(dna1)):
        if dna1[i] != dna2[i]:
            total += 1
    return total  #Made by Zach

def count_dom_phenotype(genotypes):     #program essentially does this function:  (probability of dom offspring with that pairing)*2
    dom_offspring = 0
    dom_offspring += genotypes[0]*2
    dom_offspring += genotypes[1]*2
    dom_offspring += genotypes[2]*2
    dom_offspring += genotypes[3]*1.5
    dom_offspring += genotypes[4]*1     #we can ignore the last element in list since that is aa-aa. meaning no dominant offspring will exist
    return dom_offspring  #Made by Mark

def source_rna(protein):
    multi = 3  #start with an initial 3 because of the 'Stop' RNA
    codons = 'FFLLSSSSYYCCWLLLLPPPPHHQQRRRRIIIMTTTTNNKKSSRRVVVVAAAADDEEGGGG'
    for i in range(0,len(protein)):
        codon = protein[i]
        multi *= codons.count(codon)
    return multi  #Made by Zach

def splice_rna(dna, intron_list):
    index= 0
    rna= ''
    codon= ''
    for intron in intron_list:
        while len(locate_substring(intron, dna)) > 0:           #removes one intron at a time instead of all at once
            index= locate_substring(intron,dna)
            dna= dna[:index[0]] + dna[index[0] + len(intron):]  #dna= dna up until index of the first intron, + everything after end of intron
    rna= dna2rna(dna)
    codon= rna2codon(rna)
    return codon