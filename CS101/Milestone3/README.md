CS 101 Project Milestone #3 (Final)
===================================

Introduction
------------

You have created a fair amount of tooling and are prepared for your final twofold challenge.

1.  First, you must solve the mammoth genome! We have a collection of DNA samples which need to be assembled into one superstring containing all of the fragments.
    
2.  Finally, you must produce a short individual report on your project, discussing the functions and suggesting future directions for work.
    

In the first milestone, you built a number of functions which enable deeper analysis to take place. In this arc of the project, you will combine those tools and build the basis of deeper analysis.

As before, we are completing problems from the [Rosalind bioinformatics project](http://rosalind.info/problems/tree-view/). Each of the functions is defined below—it is up to you and your team to divide up the work and combine your code into one file.

The total contribution of Milestone #3 (`ms3`) to the project grade is 39/100 points.

### Team Check-In & Progress Report (9 points)

All teammates will check in together with the TA once a week to present your progress report and updated task list. All reports will be submitted on GradeScope.

### Final Peer Evaluation (10 points)

Your TA will release a peer evaluation survey after the deadline. This survey will be completely anonymous and privy only to yourself and the TA. This will be released on May 4 at 10 p.m. (the submission deadline for the rest of the project) and due on May 6 at 10 p.m.

*   Submit a peer evaluation on time (5 points)
    
*   Fair contribution to the Milestone as indicated by your peers (5 points)
    

**Note that you will not receive any points for the peer evaluation on your individual milestone score if you do not submit a peer evaluation on time.**

### Final Program (10 points)

We will provide you a file containing the text of many DNA samples, one each per line. You need to take this file and produce the shortest unique string containing all DNA fragments within it.

*   [Final assessment file: `ms3-dna-mammuthus.txt`](/course/cs101-fa22/file-version/0bb1d324ca416f53a303ec8e0b77109a00513c4f/./resources/ms3-dna-mammuthus.txt)

(Note: We oversimplified this problem a bit and didn't track `STOP` codons. Don't worry about those now.)

This is in general a _hard_ problem. Your `assemble_genome` from before may not be quite adequate to solve it yet. We have additionally defined the overlap between adjacent strings as being 8 characters long so that you don't have to worry about truly random overlap segments.

As a test for your methodology, we also provide smaller test files which have the specified answers. Your program should work on all of these, but you can start small to make sure that your results make sense.

*   [`ms3-dna-50.txt`](/course/cs101-fa22/file-version/0bb1d324ca416f53a303ec8e0b77109a00513c4f/./resources/ms3-dna-50.txt)
    
    `'CCGCACTCATATCTTGAATGCGATACCTTCGTTATGAGCAAATCTATAAC'`
    
*   [`ms3-dna-100.txt`](/course/cs101-fa22/file-version/0bb1d324ca416f53a303ec8e0b77109a00513c4f/./resources/ms3-dna-100.txt)
    
    `'CATGCGTGTCATCTCGTGAGGCCTCGCTGAGCGGCTTTGGTTCGATCCTCCCTCAGGGTAGTGGCTATTGCCCGGGCCGCATACTCCGTATACGACGCGT'`
    
*   [`ms3-dna-500.txt`](/course/cs101-fa22/file-version/0bb1d324ca416f53a303ec8e0b77109a00513c4f/./resources/ms3-dna-500.txt)
    
    `'TGTTTTTGGATTTGAATGGGTACCTGCGCCTGTCGGCACTTGCTTACGACCCTCCTGAACGGAGCTAGCCTTGGTTGATGACAGAACATAGAACCGGTGTGGGTGCCGCCCACTTGTTGAGCAGCGGGGCTTGCCACCGCCACAGCCTTAGTAGGGCATGATGTCTGACCCTTGCCCGCTGGTCCAGCGGTAAGCTAGCTGCGGCAATCGCATTAATCTCGACGTGGAGCGGTCTTAGTCTCCCCCAAACGCCACATGCGAGGCACCCGTACATGATCATACGATCACCGACGTCGCAAAGCATCAAGATTTGGGGACCCTACCATTGGCTGTCGCGCTTCTTACCACGAGATATGGGGTTCTCTTATCTATCAGTCCTGAACTCGATTTGGGGGATGGGTACACCTATCACACCCATGTTTGCGGGAATGGAGGGGAACGAGGTTAGACCGTAGAGTGGTGACTTAGGATAGCAAGCTCGTAGTCTGCGGCCGCGACGG'`
    
*   [`ms3-dna-1000.txt`](/course/cs101-fa22/file-version/0bb1d324ca416f53a303ec8e0b77109a00513c4f/./resources/ms3-dna-1000.txt)
    
    `'GTCGTGCGAGATCGACAGAACTCCTGAAGATGATAGTCTACGTCATTAACTTTGCCCTTTTTATGGTTAAGATGAGGTCGTTATAGCTGTAGCCGATGCCTGATTTTGCCACAGTCGAATACGACGCTTGCATTAGCTTAGCTTCGTGTACCGGGTAAGACAGATCACAAGCCAGTCTAGTGGTTACCGACTGGCTCAGGGTCACGATAGGTTCGTGTAGAACCTAGTGCTTGGAAGGCTTTAATACTCTGAGACACACGCTGCGTTAGTGAGATCTACTGATACAGATGGAAGGATACGATGTGCGTAAATCGTTCTCTCTTCATAACACCAGTCGTAAACGTTTAAGAAACCAGCCAGACTCTGCATTTATGATTTTTGTGGCTATCCGCTCATCCTCTATTTCGTAATTCCCTGATATACCACCTAGAGTTAGTCACATAGCTCACCATTTACCTCACGGCCAGATTACACCTCCGAATCGCTCACGGTGCGCAGGGGTTCAGAATCAGGTCAAATTCACTCGGTTGAGTGACACCTCTCTACAGTTGCCAAGCTACTGGCTGGGCGACATCAACGCTAGACTCTGTGGCAGTAACCACCGGCTCACCCAAATGACTACTAGTTATTGGACGTCAAATGGTGATCGACCAAGGTTCCAGGCGGGGCCGCATCGTTGCAGTACTTAAACGAACATCTAGAACGATGAGCTGCGCAAGTCTAATTTTATCCTAACCAACGCTCCCTAAAGACCTACTCACAAAACTTTTTTGTGGACGTTGGGCGTTTGCCTCAGATACATTAATATCTGCTACACCAGGCTACGCTGTTAAAGGCAAGGTAGTGGGGATCAAGAATCTGTAACTAGGCTACCTTGACGAGAATTTAGACGAGGAGCAAGCGTACCCCGAAGACGAAAGGCCATAGCGTTTCAGTTGAAACTAGTAGTACCAATCCCTGCGTTTTCGGCTCGAATCGCTAATTCTCATGTTAAATTATC'`
    
*   [`ms3-dna-5000.txt`](/course/cs101-fa22/file-version/0bb1d324ca416f53a303ec8e0b77109a00513c4f/./resources/ms3-dna-5000.txt)
    
    `'TGATCAGCGAGTGGACCGGCGGTGGTGAACTTCGAAAATCACTCAGACTCTACTATGCTCTTATACTTAGTCAACTGATATTTTTGCTGATTCGAGAAGCAGCCGTTTGCTTGTGAGGTGGGCTATCAAACAGACGCGAGGCAACGCGTGGGGTCCGGCTGGGGACACGCCTTCTAGCATACTCAGGCGTAGTCACTGGGGGTCAGAATCGATTATGGGTAGGATGTGATGGGATACCTGACCCGTAACAACGACGAGCTTCTGTACCAGCCCCTGCTCGTTCACGAGGTTTCGGAGCGAAGCTGGAGAACTGTACTAAGGCTGGAAAATGCCTTCTTGTAACTTTACTTAAAGACTATGAACACATGTTAATTTAGCTATCCAGCAATCGCATTCAGCGCAAAACTTACATAGAGGTTAAGGTGATGGGAAGCTCGGGTTTCGTTTTGTTTCCATTGCCCCCCCGTCATATGAGAATGCGTGCTGTATTCAGGCGCACCCGGTAATCTGGACTGCCCGCTTGTCCCATATCGAGGCCCCGCTCGTTTCAAAGTCTACGTTCATGGATAATCCGGACTAGCGCCAAATAGAAGAAAGAGTTAGCAGCATTCCTTCGTTTTGATCGGAGGTTCACATTCCATTAAAGCTACTAATCGTTTAATCGTTGTTCCATCCGCCTAGCTCCGGAGGGGGAATGAAAGAATGCTCTTTCTATAAGCCGTCTATTGACGTTCTAAAAAACTCGCTTAGCTTACGAGGCAATTTTGCAAAGCCCCCGACATATGATGACCCTCGTTTATAACATTACATCCATGCTGGGGTTCCACGAATAGCCCGCGTTTGAACGCACATGTAGGACTAGCAACGAGGATGGATTGCTCAAAAGCGGGATCTACCGCAACATTCGACGAGCAGCCTCTGGAATTGGTGGCCATACGGACCTTTCGCTCTATGATGCCATTAGGGCCTGGGTTAAAACGGGACCCCTGGCACGACGTACTTGGTAGGCACTGTGACTCATTGATGACTCCAGACTTTCTGCGATAGGTGAGCATGGCTGGACATAGGCCATCCGTCAGTTGCGGATAAGAAGTTTCGACAAGTCTGTCGCGGGGGCACCAATGTCAGAATCGGTGGAACGTCTGTTTGGTGCTCATACGTGAGCTAGCAGTCGCAACATTAAAACTCTCAAGGCTAGGCTCGCGTTGTCGGGGTCCAACACAACATCGCTTCTCCAATGCCGCCGCGCTCCCTGGTCCATACCTATTCAATACGAGTGCATTTGAGATAGGAATCGCACAAGGCGGTGAGACGAATAAGCTTAGTTCTCTTTTCTAGGGGTGTACAACTTATCCTGGCTGCTGGGGCTCGATGAATCGATGCTGCTCGCGTATAACCATACAACCCAACTTTATCTGGTCCCGACGGGATGCAGGTTGAATACCGAGTTATTACTGGCGAGATTTCTCGTGGGTCAGTGCCGGCTGGATCTATATAAGCGTCCAACTCTCGTCTTTTGGGAAACCACGAGCACAGCTTGAGAGAATTCGGGACGTGAAGCAACAACTATCCTTCTCCAGCATAGCGTCTATGTCCCTTACTCTTAAGCAGGATATTCAGAGAATTTTTGATAACGCTATGTATTGGAAACTATGCACACTAAGTGGTTTATCTACTATGAAGCATGGTGGGGAGCGCCCGGCTAGATACCTAACGTGTCAGAGTCTATCTACCGGGCAAATCTCTATGCACTGTCAGATCGACTTTTGCCGTCGTACCTCACGAATAAGGGAGTACCACTAGCCCAGTTTTACATCTAGCACCCCTGATAATTGCTAGAATATCAGGCGCGACTGTTATCAACACCCTTTAATGTAACTGCGGGTCCCAGCTGTTTACCAAACCGTAGCATTTCTACCAAGGTCACGCAATCACGCACATTCCCTGATTGCAAGGATTGACGAACGACAATCACTATCACCCACGAAACAGGGCATCGTAGCCGAAATAGAGCTCCGGCAGTCTTGTAACAGTCACACGTCGAACTACATCGTAAGTCCCAAGGCATTTTAGACTTCGCCAGCAGAAGGTTGTCTGATAGGCTCCAGGTTCGTGGCCGATGGTGGCGATCACGATGAGTCGCTAATTCAGGCCTACGCACTCCGCTAGAGTAACTACGGCTACGAGGCCACAGAGACAGGCGGTTTGTAATCTATTACGACGCAGATCGATGGGTTAGAATGGCTTCGCGCAGACCACGTTACGCAATCTCCCTCGCGCTCGATATAGGGAAGGTGAAGTAATCATCGCTTACGGATTCACCGGGCCTCCGCGCTCAAGTAGCTCGCTGATACGTGAGGCAGGCTTTTCTAATGCGTTTCTCTGGGCGTCTGCATGTTACATCTGCCCGCGGGTCTAAATGTTCCAACAGGCACCCCGGAAGTCAGTATGGTACGGGGTCTTGCCTGTGGAACTGGAGGCTTCGGAAGACAAAGCTTGAAGAAGTGTCTACTGCGCAGCCGTAGACGTTATGAATATCCGATCGCGCTTCCCAAACTTTTCCAGGGGACATAATGTAGTTCCCCACCCTGCAGCGGGCTTTTAACACCGGTGAGCGCACTCCATGATGTGGTAGCGTGTTACTCTTGCAGGGTAGTGAGCCTAGTTCCTTCAAGTGAACCCAATGACTTTCACTGTGACTTCATAGAGCCCCGTCTCCAGTATGACGCGTAGGATCGTGAACCCCACGAAGCCCACGCTGGATCATGAGCGCGAAGCATGAAGGGCATGCCGGTACTTGTCGACGTCACGGTCGGACTGGCTTTTCAGCTCGCGCGGGCCCCCACATACTTTACCCCCACGCGACGACGGTGGGACTCGCCGGAAACTCCCGAGATAAGGAAAGATTGCTATCCACCCGCGACAGAAGACCGTAAGCGGCGGCCTTGTGCGGTCTTAAGGAGCGGAGGTAGCGAGGGCTCAGTCGTGCTTATACGCATGTGTTAGTCGGAGCATGCAAGCAGCACATTGACACGCGGCGCCGGCCGCAGGTAGTCGAAAAAAACGTAAGGGCGTTCTAGGATTGTAAATTCTGAGGGGCTAGTGTGTCTTCTACCCAAAGGTCACTACGTCCATTTTCTTCGTACCTCGGGTCAAGACGCTTGTTGATAATATCACCGAGATTTTTGGTGGACACTTATGGAGTTCCAACTGACTTTTTAGACCCGTACGAGGGCACAATCGACACCCATCGGTGCTGGCGGATCAGAGGTTGCATTCAAAAATAGTAGTCTGGAAACCACATTCAATCAGGACTGTCGCTAAGTAACATACTTCAATGTTTAAGTGTTAGGGAATCCCATCCTTTACATGTATCGATCTCCGTCTGTTCCTTTAGACAAGCGTCTAAGACACAAGAATACAGCACCTAAATCAACTTGAGAGGATGTCGATCAAAAGATGGCGGCACCAAATGGTATGTCCTTCAACAGTCCAATTGCGCTCAGTACATCCACGATCTGTCGAACCACCAACTCTTGGAACCCGCCTTCCGTTTTCTGCCTTATAGCAAGCTAACTGCTCACCTACGCCAGGACTCGCTTTGTACCTGCATCCCGTGACCACATCTAGTTCCACAGCCGACGCGCTAAACTTCACAAACTAAGACCGCATCCGGGACCTATGCCAGCGCAGCCGTACAGCGCGGGCACCTGAGTCGCCAACATTTCGTTGTCAGCATAGGCCTTCACTGCCATATTGGGGGTAAACCACTGCAGTGGTTCACGACTTCACTTTGTGAGCGGAGCCCCATCGAAGCGAAGGACGGGATTACCCGGATATGGAACCATCCGGCGTCGGATGCCTTCCGCATATGGCGCTAATGGCAAAGGAGGGCAGTAATTAACGTTCGAATCTGTGCATCATACCTGGTCCAGCTAGCTACGTCGCTAAGAACCACGAACCTACCAGGGCCATATGAATGCTAGGATTATGGGAGCATTCCCAAGTTTTCAATCATCGACAACCATGCACTACTTTAATGGACGGCGTGTCGGGTGGTAAACGCTGGAATCAGGATCGAATGGCGTGCGGCGTGCACCCCGCGCAACAGTATTACCCTTTATCCAGATATTGTAGACCATCGTGGTACAAACCGCGACTTCAAGTTCTCAACCGAAGTGTTCGTAACACTTACGAGACTAGGCACGATGCTATACCCTGGAGAGATAATGGATTTTGGCTGTGCCCCAACATCACGATCTTAGACCGTTTAGCCTTTAGTTAACAACTAACGCTTCAAACGTGGTCTATAATGAGAGCGCTCCATTCGTTGTCACAATGAAGGACAAGTGTCACTAACTCTACATCGAGTCCCGAAATACTCGTCGTAGAGGCTAGTCACGTCTAAACGAGGTTTTGCTCATTAAGTACCGCGGAGTGGGTTAGTATCACGTGCTGGACGCCTTCAGGTGAGAAATGATTTTCGGAATCACGTAATGTTTGGAGTCTGTTCGTAGTGAAGGCTAAACCCTCGCTGCGATTACTCCATGTGAAGCCTCGCTAACTTAGTCAGGAGAGTACCCGAATCGGGGTGAGAGTTGGCTGATGTTCTGCCTGAATATTGGCGGGCGCGGCACATGCTCTTCTGAGCAACAGGGGCACCCTGGGATGGCCGGTATGAATCGTGGGCTAATTGATGCCCGTTGAATCGGGTATAACGCGTGGGAAAGCGAATTTTTACTGTTAGCACCGTGGGAGAGGTTGGAATAGGTGTCCCGGTGAATTTGCAGCCATTCTCTGTTGCGAAACTTCGCTAAGGCTTGAGACCATGAAGTCGCACTCTCTCGTAGCTAAATGCGACCGAAAACGGGGTGAATTTTGCCCAGTACGCTGGTGTGCAGCATTAATGCCGGCTATTCGAGTAATTTGTGTAGTCTTCTTCGATCTCCCTTCCATGTATGTTACCGTTTACGCCGGCGGATACAAGCGTAGAGACGCAA'`
    

Ultimately, your code will be graded on whether or not it can load the ms3-dna-mammuthus.txt data from the same directory, parse it, and assemble it into a single correct string of length 16,770.

Your submission should include the following functions in one file:

*   `load_file` which accepts a file name (such as ms3-dna-100.txt) and returns a list of strings containing DNA fragments.
*   `assemble_genome2` (to differentiate from your original) which accepts a list of strings containing DNA fragments and returns the shortest superstring. You may assume an eight-character overlap between strings; e.g. ACGTAGTCACCC and AGTCACCCTGAG have eight characters of overlap.

One way to run your entire program, therefore, would be simply one line of code:

    assemble_genome2(load_file('ms3-dna-mammuthus.txt'))
    

or to really integrate what you saw of modules:

    if __name__ == '__main__':
        assemble_genome2(load_file('ms3-dna-mammuthus.txt'))
    

As before, you will be assessed on code quality and style. You will be assessed two points for using good naming conventions for functions and variables (beyond the mandated names given below for your submission). You will be assessed another two points based on your adherence to good Python style, as outlined in the Project Rubric. Additionally, you should avoid writing redundant code that improperly repeats or reuses code from a different function.

#### Using Code

**If you have satisfactorily running code from your previous work, feel free to use it in completing the project.** However, you may not have achieved working code from your previous steps. Despair not! We provide for you some _compiled Python files_ or `pyc`s, which may be placed in the same directory as your running code to provide the library functions of the earlier milestones.

    from milestone import *
    
    assert find_splice('GTA', 'ACGACATCACGTGACG') == [2, 6, 8]
    

However, you will need to match your running Python version. If you are not sure which version of Python you installed, you can check by running `from sys import version ; version`. Take the first two numbers (`3.x`) as the version.

**Python 3.7**

*   [`milestone.pyc`](site:./resources/python37/milestone.pyc)

**Python 3.8**

*   [`milestone.pyc`](site:./resources/python38/milestone.pyc)

**Python 3.9**

*   [`milestone.pyc`](site:./resources/python39/milestone.pyc)

#### Rubric (for Code)

You will be assessed six points for the functional correctness of your code (i.e. the proportion of test cases it correctly solves). If your code solves the foregoing cases, it should be fine to solve the autograder examples.

You will be assessed two points for using good naming conventions for functions and variables (beyond the mandated names given below for your submission). You will be assessed another two points based on your adherence to good Python style, as outlined in the Project Rubric. Additionally, you should avoid writing redundant code that improperly repeats or reuses code from a different function.

### Final Report (10 points)

Your report must be a minimum of 6 pages in length (not including references, code, or figures), with 12pt font, 1-inch margins, and 1.5 line spacing. You may use Microsoft Word, Google Docs, LaTeX, or another document editor to write your report. Handwritten reports will not be accepted. Pertinent diagrams/figures should not be hand drawn. Your contents and analyses will be graded using the two rubrics below. Point rubrics adapted from several various existing report rubrics \[[1](https://www.cornellcollege.edu/library/faculty/focusing-on-assignments/tools-for-assessment/research-paper-rubric.shtml "“Example 1 - Research Paper Rubric”.  (Cornell College)")\], \[[2](http://web.mit.edu/illari/Public/labguide/rubric.html "L. Illari, “Rubric for students written reports”.  MIT Program in Atmospheres, Oceans, and Climate (PAOC).")\], \[[3](https://web.archive.org/web/20190909103302/http://sites.fas.harvard.edu:80/~ede104d1/rubrics/Rubric%20for%20the%20Assessment%20of%20the%20Argumentative%20Essay.htm "Rubric for the Assessment of the Argumentative Essay.  (Harvard University)")\], \[\[4\]\[4\]\].

Your report should contain the following sections:

#### Introduction

You will introduce the course project and any relevant background information (pretend your readers know absolutely nothing about this project). Include a brief roadmap for the rest of your paper. Write a thesis statement that describes the purpose and contents of your team’s literature review.

#### Technical Analysis of Project Functions

**Team contribution breakdown:**

*   Create a table that documents the work distribution amongst your team members, including names, netIDs, team roles, and which functions each member contributed to. Include any other significant contributions.

**Technical analysis:**

*   Every team member will write a succinct analysis and reflection on a function from M1 and a function from M2 that they worked on (e.g. in a team of four, your team will write about 8 functions, four from each milestone). You must include: function purpose, limitations, difficulties, debugging strategies, and application of class material with respect to each individual function. If you find that this framework results in a significantly unbalanced workload, distribute as you see fit.

#### Literature Review

Each team member must select a piece of credible academic literature to conduct their literature review \[[5](https://www.scribbr.com/dissertation/literature-review/ "S. McCombes, “The Literature Review: A Complete Step-by-Step Guide”.")\]. **The goal of your literature review is to augment, alter, or improve the course project in a novel way.** Your team members’ analyses should be connected in some way — you can compare and contrast different topics or aggregate related topics. Your literature does not have to be limited to the CS field, but your analysis should be thorough and creative! We suggest using Google Scholar and the UIUC Library proxy search bar to gain access to a variety of scholarly articles.

#### Conclusion

Wrap up with a summary of the main topics in your lit review, including your insights and main takeaways from yoru analysis.

#### References

You must cite at least 1 credible source _per teammate_ in your literature review using IEEE citation style \[[6](https://ieee-dataport.org/sites/default/files/analysis/27/IEEE%20Citation%20Guidelines.pdf "“How to Cite References: IEEE Documentation Style”.  IEEE DataPort.")\].

\[4\]: A. Sowalsky, “Research Paper Grading Rubric.” Harvard University.

#### Rubric (for Report)

**Report Structure (5 points)**

1 pts

0.75 pts

0.5 pt

0.25 pts

0 pts

Introduction

Introduction contains detailed explanation of the purpose, relevant background information, and cohesive, clear thesis statement of the literature review.

Introduction contains a basic explanation of purpose, some background information, and a thesis statement of the literature review.

Introduction states the thesis but does not adequately explain the purpose or provide background information.

Thesis statement is vague or unclear. Purpose and background information are random, unclear, or unrelated.

Lit Review

Demonstrates well-developed focus, thorough integration of additional academic resources, and logical organization between topics. Reveals conceptual knowledge of and connection to key concepts from course materials. Description and analysis of literature is clear, accurate, professional and detailed. Substantially evaluates applied concepts and develops insights and assertions about the literature that could augment the project.

Demonstrates a clear focus, substantial integration of references, and logical organization between topics. Reveals adequate conceptual knowledge and connection to key course concepts and materials. Above-average, clear, appropriate use of literature. Demonstrates understanding of context and develops insights and assertions to augment the project in some way.

Demonstrates noticeable focus, adequate integration of references, and noticeable pattern of organization between topics. Exhibits sporadic conceptual knowledge and partial connection to key course concepts. Limited use of outside references or use of non-academic resources. Mostly clear and accurate use of literature. Demonstrates limited understanding of the context in which the literature can be applied to augmenting or changing the project.

Demonstrates some focus, minimal integration of references, and lapses in organization of topics. Exhibits little to no integration of readings, deficient conceptual knowledge and/or lack of connection to course concepts. No additional outside academic sources. Insufficient, unclear, or inappropriate use of literature. Demonstrates limited understanding of context and does not sufficiently extend analysis into augmenting the project.

Conclusion

Conclusion summarizes the main topics of lit review without redundancy; writer's opinions and suggestions for future extensions of the project are logical and well thought out.

Conclusion summarizes main topics of the lit review. Some suggestions for change and future work are evident.

Conclusion summarizes main topics of lit review, but contains redundant content. Very few suggestions for change and/or opinions are included.

Conclusion summarizes main topics of lit review, but contains redundant content. No suggestions for change and/or opinions are included.

Mechanics

Consistently appropriate and precise language for the assignment. Sentence structure, punctuation, and capitalization are correct. Any included code is clear, well-formatted, and written in typewriter font. Screenshots not permissible.

Appropriate and precise language with occasional lapses. Sentence structure is generally correct, with one or two errors. Included code is well-formatted and most is written in appropriate font. Contains some screenshots.

Somewhat precise language. Work contains some structural weaknesses and grammatical errors. Included code is not well-formatted and/or in an appropriate font. Contains multiple screenshots of code, oftentimes unnecessary.

Frequent lapses in concrete language. Work contains multiple incorrect sentence structures. Included code is poorly formatted and not in an appropriate font. Contains many unnecessary screenshots of code.

References [2](http://web.mit.edu/illari/Public/labguide/rubric.html "L. Illari, “Rubric for students written reports”.  MIT Program in Atmospheres, Oceans, and Climate (PAOC).")

Source material is well integrated in the Future Work section and accurately cited in IEEE citation format on the References page. A minimum of 1 credible source PER TEAMMATE must be included.

Source material is used. Most sources are accurately documented in IEEE citation format. At least 1 source per teammate is included, but not all are credible.

Integration of source material is awkward. All sources are accurately documented, but not completely in the desired format. Less than 1 source per teammate used and/or multiple sources are unreliable.

Lacks sources and/or all sources are unreliable; Sources are not accurately documented or in the correct format.

**Technical Analysis (5 points)**

1 pts

0.75 pts

0.5 pt

0.25 pts

0 pts

Purpose

Detailed description of what each function does. Demonstrates a thorough understanding of what was written and how it is used.

Descriptions are adequate but lack a deep understanding of what a function is supposed to do.

Descriptions include a high-level description of the function but do not provide details.

Descriptions are unclear or include functionalities that do not exist.

Limitations

Thoughtful reflection on downsides of individual functions is clear, convincing, and informative.

Most descriptions of downsides are complete, clear, and informative.

Many descriptions are only somewhat complete, lack clarity, or lack information.

Descriptions for some functions are entirely missing, are difficult to understand, or lack depth.

Difficulties

Thorough analysis and presentation of difficulties encountered including team communication and coding challenges.

Surface-level analysis of difficulties encountered.

Minimal account of difficulties either team communication or coding challenges.

Completely missing difficulties encountered either with team communication or coding challenges.

Debugging

Presentation of each debugging strategy implemented is well motivated, clearly explained, and insightful.

Presentation of each debugging strategy implemented is well motivated and satisfactorily explained.

Presentation of each debugging strategy implemented is explained, but is not extensive or is missing motivation.

Presentation of strategy is missing logic or is unclear.

Application of Class Material

Section is clearly worded, demonstrates a robust understanding of concepts and their application, and includes pertinent examples from code written.

Section is clearly worded, demonstrates an adequate understanding of concepts and their application, and includes examples from code written.

Section demonstrates an adequate understanding of concepts and their application, but examples from the project code are unrelated or tangential.

Section lacks understanding of course concepts and few if any examples from the project code are given.

### Submission

The Integrator is responsible for submitting one Python file per group to [Gradescope](https://gradescope.com). Make sure you add your team members in your submission.

The Integrator is also responsible to submit the team's report on GradeScope.

*   **Late submissions:** No late submissions are allowed for this > final submission.
    
*   **Missing teammates:** 1 point will be deducted from your total > Milestone score if you do not add your grade members to your > Gradescope submission by the deadline!
    

Once the autograder is updated and online, please submit early and frequently to check your progress.