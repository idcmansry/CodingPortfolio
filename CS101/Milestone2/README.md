CS 101 Project Milestone #2
===========================

Introduction
------------

In the first milestone, you built a number of functions which enable deeper analysis to take place. In this arc of the project, you will combine those tools and build the basis of deeper analysis.

As before, we are completing problems from the [Rosalind bioinformatics project](http://rosalind.info/problems/tree-view/). Each of the functions is defined below—it is up to you and your team to divide up the work and combine your code into one file.

The total contribution of Milestone #2 (`ms2`) to the project grade is 34/100 points.

### Team Check-In & Progress Report (6 points)

Once a week on Friday at 22:00 (10pm), each group will submit one progress report on Gradescope. The following items should be included in the report. The numbers in parentheses represent the fraction of points available for each item.

*   Roles assigned (1/8)
*   Functions assigned or an update on the progress on the individual > functions (1/4)
*   Future work planned to finish the milestone before the deadline (1/4)

The submission should include all group members.

If the TA deems it necessary, a follow-up meeting may need to be planned with a group to answer questions and help teams get out of ruts.

Half of the check-in points will be evenly divided among the weekly progress reports. The other half will be awarded based on attendance at the project work day.

### Peer Evaluation (4 points)

Your TA will release a peer evaluation survey after the deadline. This survey will be completely anonymous and privy only to yourself and the TA. This is your chance to voice any concerns (or lack thereof) about your team so we can get things on track for the next leg of the project.

*   Submit a peer evaluation on time (2 points)
    
*   Fair contribution to the Milestone as indicated by your peers (2 points)
    

### Coding Style (4 points)

You will be assessed two points for using good naming conventions for functions and variables (beyond the mandated names given below for your submission). You will be assessed another two points based on your adherence to good Python style, as outlined in the Project Rubric. Additionally, you should avoid writing redundant code that improperly repeats or reuses code from a different function.

**Level up!**

### Submission

The Integrator is responsible for submitting one Python file per group to [Gradescope](https://gradescope.com). Make sure you add your team members in your submission.

*   **Late submissions:** 5 points will be deducted from your total > Milestone score per day after the deadline.
    
*   **Missing teammates:** 1 point will be deducted from your total > Milestone score if you do not add your grade members to your > Gradescope submission by the deadline!
    

Once the autograder is updated and online, please submit early and frequently to check your progress.

### Coding Assignment (20 points)

Create your own Python file in a code editor of choice and begin writing functions as defined below. Your function names, inputs, and outputs should be exactly as described. Please make sure you follow the coding guidelines from the main rubric!

**If you are using any of your code from Milestone #1, you will need to copy it over to your new Milestone #2 file.**

Any resources you use in understanding and composing your code should be cited. Don't copy code from websites like Stack Overflow or Chegg. **Do your own work.** You can submit your work from `lab03` where there is overlap.

We aren't going to answer many questions about this on Campuswire, and you shouldn't share your code there. TAs and CAs can give some very broad feedback on code style and approach, but we want this to be, on net, as hard as an exam but without the time pressure. It's a test of your skill and a challenge of your ability to adapt and grow with somewhat open-ended requirements. We strongly recommend getting help from your teammates for debugging code and begin writing functions as soon as possible.

### Tips for testing your code:

When you're testing each of your functions, think about the following:

*   When would your function return an empty string/list/etc?
    
*   Can your code handle inputs of different lengths?
    
*   Are you hardcoding too much? (AKA are you coding to match the test case instead of handling all cases?)
    
*   Does your code work exactly as the function specified, or does it do extra/not enough work?
    
*   We provide a [set of test cases](/course/cs101-fa22/file-version/0bb1d324ca416f53a303ec8e0b77109a00513c4f/./resources/ms-tests.pdf) you can use to more rigorously test your function behavior for each case below.
    
*   Make sure that you follow the instructions exactly. Don't name the file something other than the autograder specifies. Don't upload a Word file or a PDF. Don't upload a test file including `input`. **The autograder's say is final.**
    

Assignment
----------

### `def find_splice(dna_motif, dna)`

This function should accept as argument two strings representing a DNA motif `dna_motif` (a subsequence of `dna`) and a DNA sequence `dna`, and return the index positions of the motif characters for the _first_ occurrence of the substring within `dna`. A subsequence is a collection of symbols contained in a specific order but not necessarily contiguously. This means that the pattern may be interrupted by other characters. (HINT: recall that Python is 0-indexed, meaning we start counting positions at 0...)

If the motif is not present, an empty list should be returned.

#### Example:

*   Sample input DNA snippet:
    
    `"GTA"`
    
*   Sample input DNA string:
    
    `"ACGACATCACGTGACG"`
    
*   The returned position list should be:
    
    `[2, 6, 8]`
    

### `def shared_motif(dna_list)`

This function should accept a list of DNA strings and return the longest common substring. A substring is a _contiguous_ sequence of characters within a string. A _common_ substring is a substring of every element in the given list of DNA strings. Note that the number of DNA strings in the input list is not always the same! There may be multiple solutions, but you only need to return the first one.

HINT: You may find it easier to compose the function as a flowchart or verbal/text description first, then fill in the parts of the process. How would you do this by hand?

#### Example:

*   Sample input DNA list:
    
    `["GATTACA", "TAGACCA", "ATACA"] ["ATATACA", "ATACAGA", "GGTATACA"]`
    
*   The returned longest common substring:
    
    `"TA" "ATACA"`
    

### `def get_edges(dna_dict)`

This function should accept a dictionary that maps DNA strings to their `ROSALIND` identifiers and return an adjacency list.

> To solve this problem, we need a little bit of _graph theory_, the theory of connected points. We call the points _nodes_ and the connections between them _edges_.
> 
> ![](https://mathworld.wolfram.com/images/eps-gif/GraphNodesEdges_1000.gif)
> 
> An _adjacency list_ is a list containing the edges of a graph with labeled nodes. Each item in the list contains two node labels which correspond to a unique edge in the graph.
> 
> For instance, think about the United States of America. Each state can be described as a node and the adjacent states connected by edges. For instance, there is no direct connection between Texas and Kansas, but they both have an edge in common with Oklahoma.
> 
> ![](https://mathworld.wolfram.com/images/gifs/ContiguousUSAGraph.gif)
> 
> Check out [this video](https://www.youtube.com/watch?v=LFKZLXVO-Dg&ab_channel=Reducible) for a helpful, basic intro to graph theory!
> 
> *   [Wolfram MathWorld, “Contiguous USA Graph”](https://mathworld.wolfram.com/ContiguousUSAGraph.html)

You will find the adjacencies in an _overlap graph_, where the nodes are DNA strings, and they are connected by an edge if the last three nucleotides of one node match the first three nucleotides of another. **In other words, two DNA strings are connected by an edge if the 3-character suffix of one DNA string matches the 3-character prefix of the other.** The `get_edges` function should return a list of edge adjacencies, where each edge adjacency is a tuple (or list) of ROSALIND identifiers. (Note that a string can't be adjacent to itself.)

#### Example:

*   Sample DNA dictionary:
    
    The returned adjacency list
    
    `{ "Rosalind_0498" : "AAATAAA", "Rosalind_2391" : "AAATTTT", "Rosalind_2323" : "TTTTCCC", "Rosalind_0442" : "AAATCCC", "Rosalind_5013" : "GGGTGGG" }`
    
*   Results:
    
    `[ ("Rosalind_0498", "Rosalind_2391"), ("Rosalind_0498", "Rosalind_0442"), ("Rosalind_2391", "Rosalind_2323") ]`
    

Visually,

![](/course/cs101-fa22/file-version/0bb1d324ca416f53a303ec8e0b77109a00513c4f/./img/adjacency.png)

### `def assemble_genome(dna_list)`

This function should accept a list of DNA strings and return the shortest superstring containing all given DNA strings. A superstring is a string that contains each of the smaller provided strings as a substring. Recall, a substring is a _contiguous_ sequence of characters within a string. Assume that the strings will all be the same length.

> Conceptually, think of this as “how can we mash up words into one big word?”. For instance, think of the following words:
> 
> `"COUNTER" "ERR" "RHYTHMIC"`
> 
> A little bit of thought and perhaps work with a pencil will yield the superstring `"COUNTERRHYTMIC"` as the shortest superstring. In this case, there's one relatively obvious answer, but other superstrings include `"ERRHYTHMICOUNTER"` and `"RHYTHMICOUNTERR"`. We reject the first of these as an answer because it isn't the shortest superstring (with length of 16) but the latter has the same length, 15, as the original suggested answer. In this case, there are two best superstrings; this may not always be the case.
> 
> As another example, consider the words
> 
> `"UBIL" "LEEWEE" "EWEEK" "JUB"`
> 
> for which the shortest superstring is `"JUBILEEWEEK"`, length 11.
> 
> Generally, your strategy should be to match all possible heads and tails of strings, then track which is the shortest answer. That's the superstring you want. This is related to brute-force solution methods (which will be introduced partway through this project milestone); if you want to refer to those, this is an “exhaustive search.”

#### Example:

*   Sample DNA list:
    
    `[ "ATTAGACCTG", "CCTGCCGGAA", "AGACCTGCCG", "GCCGGAATAC" ]`
    
*   The returned shortest superstring:
    
    `"ATTAGACCTGCCGGAATAC"`
    

### `def perfect_match(rna)`

This function should accept an RNA string and return the total possible number of perfect matchings of nucleotide bases.

For a graph $G$, a matching is a collection of _edges_ for which no _node_ belongs to more than one edge in the collection. A matching on $G$ is perfect if every node in the graph is matched; in other words, every nucleotide is paired (each U has a corresponding A and each C has a corresponding G) in a perfect match.

Matching nucleotides is part of important RNA base pairing interactions such as RNA folding, a process in which the single-stranded RNA molecule twists around on itself.

> This function can be a little hard to understand. Essentially, we need to calculate how many different ways each C can match to a corresponding G, for instance. Sometimes numbering these can help:
> 
> $$ C\_{1}A\_{1}C\_{2}U\_{1}A\_{2}G\_{1}U\_{2}G\_{2}C\_{3}G\_{3}A\_{3}U\_{3} $$
> 
> In this example, a perfect matching would be $C\_{1}$ → $G\_{1}$, etc. But since there are many $G$s to which each $C$ can match, there are more than one unique way to match: $C\_{1}$ → $G\_{2}$ and $C\_{1}$ → $G\_{3}$, for instance.
> 
> The bonding graph, shown after the sample input below, is an attempt to visualize these different possible matchings. Your solution approach will look rather like `assemble_genome`, with each pairwise matching being counted up until you know how many total perfect matches are possible.

#### Example:

*   Sample input RNA string::
    
    `"CACUAGUGCGAU"`
    
*   The returned total number of perfect matchings:
    
    `36`
    

![](/course/cs101-fa22/file-version/0bb1d324ca416f53a303ec8e0b77109a00513c4f/./img/graph-edges.png)

### `def random_genome(dna, gc_content)`

This function should accept a DNA string and an array of [GC-content](https://en.wikipedia.org/wiki/GC-content) values, and return the common logarithm ($\\log\_{10}$) of the probability that a random string constructed with the given GC-content will match the given DNA string exactly.

GC-content is used to identify different sectors of DNA, determine chemical properties, and other applications. For our mathematical ends, GC-content offers natural symbol frequencies for constructing random DNA strings. Let $x$ represent an element in GC-content; then the symbol frequencies of C-G and A-T are:

$$ \\text{CG}\_\\text{frequency} = \\frac{x}{2} $$

$$ \\text{AT}\_\\text{frequency} = \\frac{1 - x}{2} $$

For example, if we were to build a random string with GC-content of 40%, then the probability of the next symbol being G or C is 0.2; the probability of the next symbol being A or T is 0.3. Since probabilities may wind up being very small, we will take the common (base 10) logarithm for the sake of comparison.

> Let's think about the problem backwards for a moment. Consider the string
> 
> `ATGCATGC`
> 
> which has a GC-content of 50% or 0.5. This means if we are comparing to any other arbitrary string, we can calculate how likely the other string is to match this one.
> 
> If we construct any random string with the same GC-content of 0.5, then the likelihood that it matches this one is
> 
> $$ \\text{GC}\_\\text{frequency} = \\frac{0.5}{2} = \\frac{1}{4} $$
> 
> $$ 25\\% \\times 25\\% \\times 25\\% \\times 25\\% \\times 25\\% \\times 25\\% \\times 25\\% \\times 25\\% = (25\\%)^{8} = 0.000015258 $$
> 
> or, in terms of our $\\log\_{10}$ formulation, -4.8.
> 
> You could also think of this like password cracking: if you knew the letter distribution of a password, how many possible passwords could you construct out of those letters?

Calculate the common logarithm (logarithm base-10) of the probability that a random string constructed with the GC-content from the given list will match the given DNA string exactly. `random_genome()` should return a list of logarithms containing these calculations.

> If you are familiar with chemistry, this is a bit like a pH calculation, where the final number yields the power-of-ten magnitude of likelihood.

#### Example:

*   Sample input DNA string:
    
    `"ACGATACAA"`
    
*   Sample GC-content array:
    
    `[0.129, 0.287, 0.423, 0.476, 0.641, 0.742, 0.783]`
    
*   The returned list of log probabilities:
    
    `[-5.737, -5.217, -5.263, -5.360, -5.958, -6.628, -7.009]`
    

### `def rev_palindrome(dna)`

This function takes in a DNA string and returns the position and length of every reverse palindrome in the string with length between 4 and 12 as a list of tuples. A DNA string is a reverse palindrome if it is equal to its reverse complement. (HINT: you wrote a function to find reverse complements in Milestone 1...!) The tuples should be of the form (position, length), but you may return these pairs in any order.

To get the reverse complement, you take the complement and flip the order.

`AAAtttCCCg` becomes `cccGGGaaaTTT` (lower case to help you see)

So a reverse palindrome would be one like this:

`aaaCCCgggTTT` becomes `AAAcccGGGttt`

Note that this shares logic with `shared_motif`, so please consult your group's solution for that function if you like.

#### Example:

*   Sample input DNA string:
    
    `"TCAATGCATGCGGGTCTATATGCAT"`
    
*   The returned list of (position, length) tuples:
    
    `[ (3, 6), (4, 4), (5, 6), (6, 4), (16, 4), (17, 4), (19, 6), (20, 4) ]`