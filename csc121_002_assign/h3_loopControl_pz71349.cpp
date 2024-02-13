/*
====================================================================================
Course: Harper CSC121-002 by Mr. Jin Guo, Spring 2023
Student Name: Zach Perkins

Program Name: Loop Control
Program Description: 	
	This program takes two positive integers a and b, where a <= b, and calculate 
	the sum of the naturally increased list <a, a+1, a+2, ...b>.

Instructions: 
	1. Understand, compile and run the given program without any change.
	2. Run h3_JG.out a couple of times. When you're done, your program should 
		perform the same as this one does. Refer to the sample output at the end.
	3. The given program has used for-loop to get the job done. You need to 
		implement the same logic with while-loop and do-loop.
	4. Add your code to wherever is marked "Your code below...". Please do not 
		remove any existing statements. The given variables should be re-used 
		whenever is possible.
	5. Submit only your .cpp file. Name your file properly as usual.

References:
	s03a_simple_loop_control_demo.cpp
	s03b_loop_with_for_do_while.cpp

Created: 9/19/2009 by Jin Guo.
Updated: 9/11/2014 by Jin Guo. Customized for Harper.
Updated: 9/21/2020 by Jin Guo. Changed for new semester with minor improvements.
Updated: 12/30/2023 by Jin Guo. Adapted for this semester.
====================================================================================
*/
#include <iostream> 

using namespace std;

int main()
{
	cout << "======================================================================\n";
	cout << "Harper CSC121-002 by Mr. Jin Guo: Assignment #3, Spring 2023 \n";
	cout << "Student: Zach Perkins\n\n";
	cout << "This program will add all the integer numbers in a list such as\n";
	cout << "<3,4,5,...9> together. The two input integers are lower and upper\n";
	cout << "bounds. They must be positive and the second one cannot be smaller\n";
	cout << "than the first one.\n";
	cout << "======================================================================\n\n";

	int a; // low bound.
	int b; // high bound.

	cout << "Input lower bound (a positive integer, e.g., 1) ==> ";
	cin >> a;
	cout << "Input upper bound (a positive integer, e.g., 100) ==> ";
	cin >> b;
	cout << "\n";

	// Check wrong inputs.
	if (a < 0 || b < 0) // "||" means "or"
	{
		cout << "Sorry, both bounds must be positive - bye!\n\n";
		exit(1); // abnormal exit.
	}

	if (b < a)
	{
		cout << "Sorry, upper bound cannot be smaller than lower bound - bye!\n\n";
		exit(1); // abnormal exit.
	}

	if (a == b) // for special inputs
	{
		cout << "You have input two bounds which are the same.\n"
			<< "This means only one item in the list.\n";
		cout << "So the sum = " << a << "\n\n";

		return 0;
	}

	int i;			// started with a and increased by 1 until b is reached.
	int sum = 0;	// used for summary.

	for (i = a; i <= b; ++i)
	{
		sum = sum + i;	// or sum += i;
	}

	cout << "Using \"for loop\", sum = " << sum << "\n";

	/*
	!!!Notes: Just re-use variables i and sum for your code!!!
	======================================================================
	<<<<<< Your code below ... to implement the above with while-loop>>>>>
	======================================================================
	*/
	
	i = a;			// reset i
	sum = 0;		// reset sum
	
	while (i <= b)
	{
		sum = sum + i;
		
		++i;
	}
	
	cout << "Using \"while loop\", sum = " << sum << "\n";
	
	/*
	!!!Notes: Just re-use variables i and sum for your code!!!
	====================================================================
	<<<<<< Your code below ... to implement the above with do-loop>>>>>
	====================================================================
	*/
	
	i = a;			// reset i
	sum = 0;		// reset sum
	
	do
	{
		sum = sum + i;
		
		++i;
	} while (i <= b);
	
	cout << "Using \"do loop\", sum = " << sum << "\n";
	
	
	cout << endl;
}

/* A Sample Output
======================================================================
Harper CSC121-002 by Mr. Jin Guo: Assignment #3, Spring 2023
Student: Zach Perkins

This program will add all the integer numbers in a list such as
<3,4,5,...9> together. The two input integers are lower and upper
bounds. They must be positive and the second one cannot be smaller
than the first one.
======================================================================

Input lower bound (a positive integer, e.g., 1) ==> 1
Input upper bound (a positive integer, e.g., 100) ==> 100

Using "for loop", sum = 5050
Using "while loop", sum = 5050
Using "do loop", sum = 5050

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

