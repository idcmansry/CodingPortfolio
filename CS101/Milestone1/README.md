   CS 101: Fall 2022 - RELATE const rlUtils = rlBase.rlUtils; const tmpl = rlBase.tmpl; const bootstrap = rlBase.bootstrap;

[CS 101 Fall 2022](
  
    /course/cs101-fa22/
  
)

@import url('https://fonts.googleapis.com/css?family=B612'); @import url('https://fonts.googleapis.com/css?family=Ubuntu'); @import url('https://fonts.googleapis.com/css?family=Ubuntu%20Mono'); html { font-family: 'B612', sans-serif; } @supports (font-variation-settings: normal) { html { font-family: 'B612', sans-serif; } } h1, h2 { font-family: B612, Helvetica, Arial, sans-serif; color: 3b1c32; size: 36px; } h2, .h2 { font-family: B612, Helvetica, Arial, sans-serif; color: 3b1c32; size: 30px; padding-top: 5px; padding-bottom: 5px; font-size: 20px; border-color: #eec275; margin-top: 0px; margin-left: -5px; } h3, .h3 { font-family: B612, Helvetica, Arial, sans-serif; color: 3b1c32; size: 24px; padding-top: 5px; padding-bottom: 5px; font-size: 20px; border-color: #eec275; margin-top: 0px; margin-left: -5px; } p { font-family: B612, Ubuntu, Arial, sans-serif; padding-bottom: 20px; } @media (min-width: 1200px) { .container{ max-width: 970px; } } blockquote { padding: 10px 20px; margin: 0 0 20px; font-size: inherit; padding-left: 5px; padding-top: 0; padding-bottom: 0; padding-right: 0; border: 0px solid; border-left: 5px solid #eee; padding-bottom: 5px; background-color: #fbfef9; } code, pre { font-family: Ubuntu Mono; Courier; monospace; } <!-- Color Scheme: 9CC0EE 228 0 102 EBA79D 234 196 53 ADCC83 3 206 164 D1B983 52 89 149 5D5D5D 93 93 93 -->

CS 101 Project Milestone #1
===========================

Introduction
------------

`lab03` `dna` introduced you to writing functions that manipulate DNA strings. We'll kick off the project with similar problems. Your team will be building off parts of Lab03 to complete problems from the [Rosalind bioinformatics project](http://rosalind.info/problems/tree-view/). Each of the functions is defined below --- it is up to you and your team to divide up the work and combine your code into one file.

The total contribution of Milestone #1 (`ms1`) to the project grade is 27/100 points.

### Team Check-In & Progress Report (8 points)

All teammates will check in together with the TA once a week to present your progress report and updated task list. Delivery method will be up to your section TA.

### Peer Evaluation (2 points)

Your TA will release a peer evaluation survey after the deadline. This survey will be completely anonymous and privy only to yourself and the TA. This is your chance to voice any concerns (or lack thereof) about your team so we can get things on track for the next leg of the project.

*   Note that you will receive a **2-point deduction** to your _individual_ milestone score if you do not submit a peer evaluation.

### Coding Style (2 points)

You will be assessed one point for using good naming conventions for functions and variables (beyond the mandated names given below for your submission). You will be assessed another point based on your adherence to good Python style, as outlined in the Project Rubric.

### Submission

The Integrator is responsible for submitting one Python file per group to [Gradescope](https://gradescope.com). Make sure you add your team members in your submission. The file should be called milestone1.py.

*   **Late submissions:** 5 points will be deducted from your total > Milestone score per day after the deadline.
    
*   **Missing teammates:** 1 point will be deducted from your total > Milestone score if you do not add your grade members to your > Gradescope submission by the deadline!
    

### Coding Assignment (15 points)

Create your own Python file in a code editor of choice and begin writing functions as defined below. Your function names, inputs, and outputs should be exactly as described. Please make sure you follow the coding guidelines from the main rubric!

### Some Friendly Advice

This is the second time we've run this project. We learned a lot the first time. We make the following recommendations:

1.  Don't leave this to the last minute. Form a work plan with your team. If your team is unresponsive, communicate early with your TA.
2.  Don't share code with other teams. It is easy to check for cheating in CS 101, and we will. Adding comments or changing variable names won't trick us either. **Do your own work.** If you collaborate with someone, make sure that both of you let us know that you developed the code together.
3.  When you report who did what work, make sure that it's accurate. We may come back later with questions in subsequent assignments and you need to understand what you did and were responsible for.
4.  Make sure that you follow the instructions exactly. Don't name the file something other than the autograder specifies. Don't upload a Word file or a PDF. Don't upload a test file including `input`. **The autograder's say is final.**

Any resources you use in understanding and composing your code should be cited. Don't copy code from websites like Stack Overflow or Chegg. **Do your own work.** You can submit your work from `lab03` where there is overlap.

We aren't going to answer many questions about this on Campuswire, and you shouldn't share your code there. TAs and CAs can give some very broad feedback on code style and approach, but we want this to be, on net, as hard as an exam but without the time pressure. It's a test of your skill and a challenge of your ability to adapt and grow with somewhat open-ended requirements.

Assignment
----------

### `s(dna)`

This function should accept as argument a string representing a DNA sequence and return a dictionary representing the number of times each nucleotide A, C, G, or T occur in the DNA string, in that order. (HINT: You did this and a few other things in `lab03`.)

#### Example:

*   Sample input DNA string:
    
    `"AGCTTTTCATTCTGACTGCAACGGGCAATATGTCTCTGTGTGGATTAAAAAAAGAGTGTCTGATAGCAGC"`
    
*   The returned dictionary should be:
    
    `{'A': 20, 'C': 12, 'G': 17, 'T': 21}`
    

### `dna2rna(dna)`

This function should accept a string representing a DNA sequence and return the transcribed RNA string. DNA sequences are transcribed to RNA sequences by replacing all occurrences of the `"T"` nucleotides with `"U"`. _This is similar to what you did in the lab but does not include the complement of the DNA._

#### Example:

*   Sample input DNA string:
    
    `"GATGGAACTTGACTACGTAAATT"`
    
*   The returned RNA string:
    
    `"GAUGGAACUUGACUACGUAAAUU"`
    

### `reverse_complement(dna)`

This function should accept a string representing a DNA sequence and return the reverse complement as a new string. The reverse complement of a DNA string is formed by reversing the entire string, and then taking the complement of each nucleotide. Recall from `lab03` that `"A"` and `"T"` are complements of each other, as are `"C"` and `"G"`.

#### Example:

*   Sample input DNA string:
    
    `"AAAACCCGGT"`
    
*   The returned reverse complement string:
    
    `"ACCGGGTTTT"`
    

### `mendels_law(hom, het, rec)`

Gregor Mendel's laws of inheritance state that organisms possess a pair of alleles for a given trait. If those two alleles are the same, then it is called homozygous; if they are different, it is heterozygous. For a given trait, are two possible alleles: dominant and recessive. Only one dominant allele is necessary for the trait to be expressed. Watch this [three-minute TED-Ed video](https://www.youtube.com/watch?v=Mehz7tCxjSE&ab_channel=TED-Ed) for a more detailed explanation of Mendel's laws.

The `mendels_law()` function should accept three positive integers representing:

1.  the number of organisms that are homozygous dominant (`AA`);
2.  the number of organisms that are heterozygous (`Aa`); and
3.  the number of organisms that are homozygous recessive (`aa`)

for a breeding population. It should return the probability that the offspring of two randomly selected organisms will possess a dominant allele (AKA it displays the dominant phenotype).

The trick to getting this right is to think about Punnett squares and combinations of genes. The probability that any organism receives a dominant allele comes from:

$$ P\_{\\text{dom}} = \\frac{n\_{\\text{dom}}}{n\_{\\text{total}}} or 1 - n\_{\\text{recessive}}/n\_{\\text{total}} $$

worked out for _each_ pairing. That can be complicated or simple, depending on how much you want to check things ahead of time on paper.

#### Example:

*   Sample function calls with integer inputs:
    
    `mendels_law(2, 2, 2) # AA, AA, Aa, Aa, aa, aa mendels_law(1, 1, 0) # AA, Aa mendels_law(4, 0, 2) $ AA, AA, AA, AA, aa, aa mendels_law(0, 4, 0) $ Aa, Aa, Aa, Aa`
    
*   The returned probabilities:
    
    `0.78333 1.0 0.93333 0.75`
    

### `fibonacci_rabbits(n, k)`

This function should accept two integers $n$ and $k$, and calculate the total number of rabbit pairs that will be present after $n$ months, given that every pair of mating rabbits produces $k$ rabbit pairs in their next litter (in the next month). Assume we begin with one pair, and that the reproduction of rabbits is represented by the Fibonacci sequence (which was actually a mathematical exercise to calculate the population of rabbits over time!):

$$ F\_{n} = F\_{n - 1} + F\_{n - 2} $$

with $F\_{1} = F\_{2} = 1$.

Note that you'll have to account for the rabbits producing $k$ pairs of offspring every generation.

As a worked example, consider a population starting with $k=1$ rabbit pair after $n=5$ months.

*   Month 1: one (baby) pair produces no new pair, 1→1
*   Month 2: one (new adult) pair produces no new (baby) pair, 1→1
*   Month 3: one (adult) pair produces one new (baby) pair, 1→2
*   Month 4: one (adult) pair and one (baby) pair produce one new (baby) pair, 2→3
*   Month 5: two (adult) pairs and one (baby) pair produce two new (baby) pairs, 3→5
*   Month 6: three (adult) pairs and two (baby) pairs produce three new (baby) pairs, 5→8

> You will also need to use a coding method called _recursion_. While we've done this implicitly in CS 101, it basically describes a situation in which a function calls itself. If you'd like to know more, you can watch [the first 4 minutes of this tutorial](http://youtube.com/watch?v=ngCos392W4w) for an overview of recursion (the rest is examples).

If you start with a different rabbit fertility rate, then you need to take into account the different starting number, e.g. for $k=3$:

*   Month 1: one (baby) pair produces no new pair, 1→1
*   Month 2: one (new adult) pair produces no new pair, 1→1
*   Month 3: one (adult) pair produces three new (baby) pairs, 1→4
*   Month 4: one (adult) pair and three (baby) pairs produce three new (baby) pairs, 4→7
*   Month 5: four (adult) pairs and three (baby) pairs produce twelve new (baby) pairs, 7→19
*   Month 6: seven (adult) pairs and twelve (baby) pairs produce twenty-one new (baby) pairs, 19→40

#### Example:

*   Sample function call with integer inputs:
    
    `fibonacci_rabbits(1, 3) fibonacci_rabbits(2, 3) fibonacci_rabbits(3, 3) fibonacci_rabbits(4, 3) fibonacci_rabbits(5, 3) fibonacci_rabbits(6, 3)`
    
*   The returned number of rabbit pairs:
    
    `1 1 4 7 19 40`
    

### `gc_content(dna_list)`

This function should accept a list of DNA strings, and return the index of the DNA string with the highest GC-content and its GC-content percentage as a tuple.

The GC-content of a DNA string is the percentage of nucleotides in the string that are `"C"` or `"G"`.

#### Example:

*   Sample input list
    
    `["CCTGCGGAAGATCGGCACTAGAATAGCCAGAACCGTTTCTCTGAGGCTTCCGGCCTTCCCTCCCACTAATAATTCTGAGG", "CCATCGGTAGCGCATCCTTAGTCCAATTAAGTCCCTATCCAGGCGCTCCGCCGAAGGTCTATATCCATTTGTCAGCAGACACGC", "CCACCCTCGTGGTATGGCTAGGCATTCAGGAACCGGAGAACGCTTCAGACCAGCCCGGACTGGGAACCTGCGGGCAGTAGGTGGAAT"]`
    
*   The returned tuple:
    
    `(2, 60.919540)`
    

### `rna2codon(rna)`

This function should accept a string representing an RNA sequence, and return the corresponding amino acid string, as transcribed by [this codon table](http://rosalind.info/glossary/rna-codon-table/). You do not need to transcribe the stop codon.

#### Example:

*   Sample RNA string:
    
    `"AUGGCCAUGGCGCCCAGAACUGAGAUCAAUAGUACCCGUAUUAACGGGUGA"`
    
*   The returned protein string:
    
    `"MAMAPRTEINSTRING"`
    

### `locate_substring(dna_snippet, dna)`

This function should accept two strings, dna\_snippet and dna, where dna\_snippet is a substring of dna, and return all locations of the substring as a list of integers. In other words, dna\_snippet may exist in multiple locations within dna; you should return the beginning index position of each occurrence of dna\_snippet inside of dna.

#### Example:

*   Sample DNA snippet (substring):
    
    `"ATAT"`
    
*   Sample DNA string:
    
    `"GATATATGCATATACTT"`
    
*   The returned position list:
    
    `[ 1, 3, 9 ]`
    

### `hamming_dist(dna1, dna2)`

This function should accept two strings representing DNA sequences of equal length and return the Hamming distance between the two strings as an integer. The Hamming distance refers to the number of corresponding symbols in the same position that differ between two sequences. In other words, you should find the number of differences between two DNA sequences.

#### Example:

*   Sample input DNA strings:
    
    `"GAGCCTACTAACGGGAT" "CATCGTAATGACGGCCT"`
    
*   The returned Hamming distance:
    
    `7`
    

### `count_dom_phenotype(genotypes)`

This function should accept a list of six nonnegative integers corresponding to the number of couples in a population possessing a specific genotype pairing, such as AA-AA (both homozygous dominant) or Aa-aa (heterozygous and homozygous recessive). The list of integers represent the number of couples having the following genotypes, in this order:

1.  AA-AA
2.  AA-Aa
3.  AA-aa
4.  Aa-Aa
5.  Aa-aa
6.  aa-aa

The function should return the expected number of offspring displaying the dominant phenotype in the next generation, assuming that every couple has exactly two offspring.

#### Example:

*   Sample input list:
    
    `[1, 0, 0, 1, 0, 1]`
    
*   The returned number of dominant phenotype offspring:
    
    `3.5`
    

### `source_rna(protein)`

This function should accept a string representing a sequence of proteins and returns the total number of different source RNA strings, modulo 1,000,000. Essentially, you are calculating how many strands of mRNA from which this particular protein could have been translated. (HINT: You'll want to use or manipulate the codon table from `rna2codon()`.)

#### Example:

*   Sample input protein string:
    
    `"MA" "CMDA"`
    
*   The returned number of possible source RNA sequences:
    
    `12 # from M ({'AUG', } → 'M' × {'GCA', 'GCU', 'GCC', 'GCG'}→ 'A') # × Stop [{'UAA', 'UAG', 'UGA'}] → 'Stop'}] ⇒ 1 × 4 × 3 = 12 48 # from 2 C × 1 M × 2 D × 4 A × 3 Stop = 48`
    

### `splice_rna(dna, intron_list)`

This function should accept a string representing a DNA sequence and a list of strings representing introns. The process of transcribing DNA into RNA involves translating the DNA to RNA and then performing RNA splicing, where the sequence is chopped into smaller segments called introns and exons. Introns are segments of the gene not used for protein translation, so they should be removed from the sequence. Exons are the remaining segments, which are then transcribed sequentially into a protein string. splice\_rna() should return a protein string that results from transcribing and translating the exons of the given string. (HINT: You should use some of your previous functions. It's similar to the last part of `lab03`.)

#### Example:

*   Sample input DNA string:
    
    `"ATGGTCTACATAGCTGACAAACAGCACGTAGCAATCGGTCGAATCTCGAGAGGCATATGGTCACATGATCGGTCGAGCGTGTTTCAAAGTTTGCGCCTAG"`
    
*   Sample intron list:
    
    `["ATCGGTCGAA", "ATCGGTCGAGCGTGT"]`
    
*   The returned protein string:
    
    `"MVYIADKQHVASREAYGHMFKVCA*"`