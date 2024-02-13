/*
====================================================================================
Course: Harper CSC121-002 by Mr. Jin Guo, Spring 2023
Student Name: Zach Perkins

Program Name: Repeat with Yes/No
Program Description:
	This program takes one integer from keyboard and calculates its factorial.
	This calculation can be repeated until the user chooses to quit.

Instructions:
	1. Understand, compile and run the given program without any change.
	2. Run h4_JG.out a couple of times. When you're done, your program should 
		perform the same as this one does. Refer to the sample output at the end.
	3. Refer to my s03c_loop_control_by_yes.cpp. You may use any of the three
		yes_no loop controls to repeat the calculation.
	4. Submit only your .cpp file. Name your file properly as usual.

Notes:
	1. The factorial of n (>=0) is defined as follows:
		n! = n*(n-1)*(n-2)*...*2*1
		0! = 1, 1! = 1;
		5! = 5*4*3*2*1
	2. If you choose the getline() version in s03c_loop_control_by_yes.cpp, you can 
		avoid to clear buffer.
	3. n! grows very fast. int type can only get right results of up to 12!. 
		int is an integer type of 4 bytes. "long int" on some computers is 4 bytes
		(e.g., on my PC and 8 bytes on others (e.g., on Ares/Unix). uint64_t is 
		an unsigned integer type of 8 bytes for all computers.

Created: 6/15/2016 by Jin Guo.
Updated: 8/25/2016 by Jin Guo. Changed for new semester. Used factorial to
		replace the result of Assignment 3.
Updated: 6/4/2021 by Jin Guo. Adapted for this semester. Introduced INT_MAX.
Updated: 9/23/2022 by Jin Guo. Adapted for this semester. Change tpye of factorial
		to be int64_t.
Updated: 2/13/2023 by Jin Guo. Adapted for this semester. 
		Change int64_t to uint64_t.
====================================================================================
*/
#include <iostream> 
#include <string>	// for string and getline()
#include <climits>  // for INT_MAX

using namespace std;

int main()
{
	cout << "======================================================================\n";
	cout << "Harper CSC121-002 by Mr. Jin Guo: Assignment #4, Spring 2023 \n";
	cout << "Student: Zach Perkins\n\n";
	cout << "This program will calculate factorial of n which cannot be negative.\n";
	cout << "This calculation can be repeated until the user chooses to quit.\n";
	cout << "======================================================================\n";
	
	/*
	==============================================================================
	Take lines 62-78 as the repeat-body and add yes_no loop control to repeat it.
	<<<<<< Your code below... >>>>>
	==============================================================================
	*/
	string repeat = "yes";

	while (repeat == "yes" | repeat == "YES") {
		
		int n = -1;		// defines the factorial value.
		while (n < 0)	// to make sure n >= 0.
		{
			cout << "\nInput a positive integer for its factorial ==> ";
			cin >> n;
			cin.ignore(INT_MAX, '\n'); // clear the buffer for next input.

			if (n < 0)
				cout << "Sorry, the input cannot be negative, please try again ...\n";
		};

		uint64_t factorial = 1;
		for (int i = n; i > 1; --i)
			factorial = factorial * i; // or: factorial *= i;

		cout << n << "! = " << factorial << "\n\n";
		
		cout << "Do you want to do this again?\n(yes/YES to continue) ==> ";
		cin >> repeat;
		cout << endl;
	}

	cout << endl; // last statement. Don't include this in your loop.
}

/* A Sample Output
======================================================================
Harper CSC121-002 by Mr. Jin Guo: Assignment #4, Spring 2023
Student: Zach Perkins

This program will calculate factorial of n which cannot be negative.
This calculation can be repeated until the user chooses to quit.
======================================================================

Input a positive integer for its factorial ==> -1
Sorry, the input cannot be negative, please try again...

Input a positive integer for its factorial ==> 5
5! = 120

Do you want to do this again?
(yes/YES to continue) ==> yes

Input a positive integer for its factorial ==> 4
4! = 24

Do you want to do this again?
(yes/YES to continue) ==> no

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

