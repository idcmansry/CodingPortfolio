/*
========================================================================================
Course: Harper CSC121-002 by Mr. Jin Guo, Spring 2023
Student Name: Zach Perkins

Program Name: Vote Counting
Program Description:
	This program will collect votes and calculate the count and percentage for 
	each presidential candidate. Two digits after decimal point should be 
	preserved for the percentage. 

Instructions:
	1. Run op6_JG.out a couple of times. When you are done, your program should perform
		the same as this one does. A sample input/output is attached at the end.
	2. Make input as secure as possible, e.g., input "Smith abc123" should not crash 
		your program. 
	3. Make the input to be tolerant as much as possible. E.g., "  Smith abc ", 
		"smiTH" or "SMITH D" should be considered to vote to Smith.
	4. You may use the given op6_in.txt as an input to test your program.
	5. Submit only your .cpp file. Name your file properly as usual.

Notes: 
	1. A function below is defined. It turns a string to lower case: 
		void strToLower(string& str);	
	2. In general, integer operations are faster and use less memory than double's.
		The rule is, "Whenever an integral type can be used, don't use a floating type."
		For example, "age", "counter" should be of unsigned int, not double. To preserve 
		the decimal part when division is applied to two integers, you need to cast 
		one of them to be double. Of course, the variable to hold the result should 
		be of double.
	3. If you run this program on Unix, you may direct input and output to files, e.g.,
		$ op6_JG.out < op6_in.txt > op6_out.txt

		The above running will take input from op6_in.txt and output the result to 
		op6_out.txt.

References:
	The reference textbook (C++ How to Program): 
		fig06_07.cpp, fig06_08.cpp and fig06_09.cpp

Created: 10/20/2016 by Jin Guo.
Updated: 10/6/2017 by Jin Guo. Added invalid count for this semester.
Updated: 3/13/2022 by Jin Guo. Changed return type of strToLower() to be void.
Updated: 3/8/2023 by Jin Guo. Adapted for this semester.
========================================================================================
*/
#include <iostream>
#include <string>
#include <iomanip>  // for setprecision() and fixed
#include <cctype>	// for tolower() and islower().
#include <climits>	// for INT_MAX

using namespace std;

// str is converted to lower case and the result is also returned.
void strToLower(string& str); 

int main()
{
	cout << "==================================================================\n";
	cout << "Harper CSC121-002 by Mr. Jin Guo: Optional #6, Spring 2023 \n";
	cout << "Student: Zach Perkins\n\n";
	cout << "This program will collect votes and calculate the count and \n";
	cout << "percentage for each presidential candidate.\n";
	cout << "==================================================================\n\n";

	/* 
	==============================
	<<<<<<<< You Code Below >>>>>>
	==============================
	*/
	
	string vote;
	int trump, biden, invalid, total;
	trump = biden = invalid = total = 0;
	
	do
	{
		cout << "Please enter which candidate you will vote?" << endl;
		cout << "(Input Trump or Biden, or end for quit) => ";
		cin >> vote;
		cin.ignore(INT_MAX, '\n');
		
		strToLower(vote);
		if (vote == "end")
		{
			cout << endl;
			break;
		}
		if (vote == "trump")
		{
			trump++;
			cout << "You voted for Trump, his count now is: " << trump << endl;
		}
		else if (vote == "biden")
		{
			biden++;
			cout << "You voted for Biden, his count now is: " << biden << endl;
		}
		else if (vote != "end")
		{
			invalid++;
			cout << "Your vote is invalid! The invalid count now is: " << invalid << endl;
		}
		total++;
		cout << endl;
	} while (vote != "end");
	
	cout << ">>> Voting is done. Now let's count who won...\n\n";
	cout << setprecision(4);
	cout << "TotalCount:" << setw(6) << total << endl;
	cout << "For Biden: " << setw(6) << biden << setw(8) << biden * 100. / total << "%\n";
	cout << "For Trump: " << setw(6) << trump << setw(8) << trump * 100. / total << "%\n";
	cout << "Invalid:   " << setw(6) << invalid << setw(8) << invalid * 100. / total << "%\n";
	
	cout << endl;
}

//----------------------------------------------
void strToLower(string& str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (isupper(str[i]))
			str[i] = tolower(str[i]);
	}
}

/* A Sample Output
==================================================================
Harper CSC121-002 by Mr. Jin Guo: Optional #6, Spring 2023
Student: Zach Perkins

This program will collect votes and calculate the count and
percentage for each presidential candidate.
==================================================================

Please enter which candidate you will vote?
(Input Trump or Biden, or end for quit) =>   biden
You voted for Biden, his count now is: 1

Please enter which candidate you will vote?
(Input Trump or Biden, or end for quit) => TRump asdf
You voted for Trump, his count now is: 1

Please enter which candidate you will vote?
(Input Trump or Biden, or end for quit) => trump don
You voted for Trump, his count now is: 2

Please enter which candidate you will vote?
(Input Trump or Biden, or end for quit) => Biden
You voted for Biden, his count now is: 2

Please enter which candidate you will vote?
(Input Trump or Biden, or end for quit) => abc BIDEN
Your vote is invalid! The invalid count now is: 1

Please enter which candidate you will vote?
(Input Trump or Biden, or end for quit) => bill
Your vote is invalid! The invalid count now is: 2

Please enter which candidate you will vote?
(Input Trump or Biden, or end for quit) => John
Your vote is invalid! The invalid count now is: 3

Please enter which candidate you will vote?
(Input Trump or Biden, or end for quit) => end

>>> Voting is done. Now let's count who won...

TotalCount:     7
For Biden:      2   28.57%
For Trump:      2   28.57%
Invalid:        3   42.86%

*/

/*
************************************************
* (C) Copyright by Jin Guo
*
* This program is free for my class students.
* For any other purpose of using this program,
* please ask for permission by sending email to:
* taiji.guo@gmail.com
************************************************
*/

