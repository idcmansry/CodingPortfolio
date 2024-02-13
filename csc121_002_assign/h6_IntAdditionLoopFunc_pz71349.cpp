/*
====================================================================================
Course: Harper CSC121-002 by Mr. Jin Guo, Spring 2023
Student Name: Zach Perkins

Program Name: Adding Two Integers
Program Description:
	This program are for kids to practice addition of two integers. Every time the 
	program runs, two random integers are generated. The user has a certain number
	of chances to get the correct answer.

Instructions:
	1. Understand the given .cpp, compile and run it a couple of times. Before and
		after your changes, the program should perform exactly the same.
	2. Add code or modify the program wherever is marked "Your code below...". 
		You need to modify the given program in three steps.
		1) Give the function prototype before main() as suggested.
		2) Define the function by moving the code of adding two integers in main()
			to the function body after main().
		3) In main(), call this function to replace the code of adding two integers.
	3. Submit only your .cpp file. Name your file properly as usual.

Notes:
	1. The function you are asked to declare and define has two parameters, one is 
		call-by-value and the other is call-by-reference.
	2. srand() is used to generate a seed for rand().

Created: 9/25/2007 by Jin Guo
Updated: 10/14/2020 by Jin Guo. Adapted for this semester. Updated instructions.
Updated: 3/15/2021 by Jin Guo. Significant changes.
Updated: 2/21/2023. Adapted for this semester. Minor changes.
====================================================================================
*/
#include <iostream>
#include <iomanip>	// for setprecision()
#include <cstdlib>	// for srand(), rand()
#include <ctime>	// for time()
#include <climits>  // for INT_MAX

using namespace std;

/*
========================================================================
<<<<<< Your code below... >>>>>

Give a function prototype required as follows.
Function name:	addTwoIntegers.
numOfTries:			number of tries for each problem. It's call-by-value.
countCorrect:	number of correct answers. It's call-by-reference.
Return type:	void.
========================================================================
*/ 
void addTwoIntegers(int numOfTries, int& countCorrect);

int main()
{
	const int numOfTries = 3; // set number of tries as a constant.

	cout << "====================================================================\n";
	cout << "Harper CSC121-002 by Mr. Jin Guo: Assignment #6, Spring 2023 \n";
	cout << "Student: Zach Perkins\n\n";
	cout << "This program will let you to practice addition of two integers.\n";
	cout << "You have " << numOfTries << " chances for the correct answer.\n";
	cout << "====================================================================\n\n";

	srand((int)time(0));	// seed random number generator.

	int countTotal = 0;		// for counting problems.
	int countCorrect = 0;	// for counting correct answers.
	char repeat;
	
	do 
	{
		++countTotal;

		cout << "-----------------------------\n";
		cout << ">>> Problem " << countTotal << ": \n";
		
		/*
		========================================================================
		<<<<<< Your code below... >>>>>
		Call the function you defined to replace the following calculation.
		========================================================================
		*/
		
		addTwoIntegers(numOfTries, countCorrect);

		cout << "\nTry another problem? (y/n) ==> ";
		cin >> repeat;
		cin.ignore(INT_MAX, '\n'); // clear the buffer for next input.
		cout << endl; // print a new line before next problem.
	} while (repeat == 'y' || repeat == 'Y');

	cout << fixed << setprecision(2);
	cout << "=========================================================\n";
	cout << "You did " << countCorrect << " right out of "	<< countTotal << " problems.\n";
	cout << "Correction ratio: " << countCorrect * 100.0 / countTotal << "%.\n";

	cout << "\n==== Thanks for using this program. See you next time! ====\n\n";
}

/*
========================================================================
<<<<<< Your code below... >>>>>
Define the function you declared before main().
========================================================================
*/
void addTwoIntegers(int numOfTries, int& countCorrect)
{
	int a, b, c;
	int answer;

	a = 1 + rand() % 99;	// generate a number between 1 and 99.
	b = 1 + rand() % 99;	// generate a number between 1 and 99.
	c = a + b;

	for (int i = 1; i <= numOfTries; ++i)
	{
		cout << "What is " << a << " + " << b << " ? ==> ";
		cin >> answer;
		cin.ignore(INT_MAX, '\n'); // clear buffer for next input.

		if (answer == c)
		{
			cout << "You got it!\n";
			++countCorrect;
			break;
		}

		if (i == numOfTries) // number of tries has been reached.
		{
			cout << "Still not correct. You have tried " << numOfTries << " times.\n";
			break; // out of for loop.
		}

		cout << "That's not correct. Try again,\n\n";
	}
}
	
/* A Sample Output
====================================================================
Harper CSC121-002 by Mr. Jin Guo: Assignment #6, Spring 2023
Student: Zach Perkins

This program will let you to practice addition of two integers.
You have 3 chances for the correct answer.
====================================================================

-----------------------------
>>> Problem 1:
What is 79 + 80 ? ==> 23
That's not correct. Try again,

What is 79 + 80 ? ==> 2
That's not correct. Try again,

What is 79 + 80 ? ==> 2
Still not correct. You have tried 3 times.

Try another problem? (y/n) ==> y abc

-----------------------------
>>> Problem 2:
What is 16 + 88 ? ==> 104
You got it!

Try another problem? (y/n) ==> y

-----------------------------
>>> Problem 3:
What is 6 + 92 ? ==> 23
That's not correct. Try again,

What is 6 + 92 ? ==> 98
You got it!

Try another problem? (y/n) ==> y

-----------------------------
>>> Problem 4:
What is 25 + 77 ? ==> 2
That's not correct. Try again,

What is 25 + 77 ? ==> 2
That's not correct. Try again,

What is 25 + 77 ? ==> 102
You got it!

Try another problem? (y/n) ==> n

=========================================================
You did 3 right out of 4 problems.
Correction ratio: 75.00%.

==== Thanks for using this program. See you next time! ====

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

