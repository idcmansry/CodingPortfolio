/*
====================================================================================
Course: Harper CSC121-002 by Mr. Jin Guo, Spring 2023
Student Name: <Your Name>

Program Name: A Simple C++ Program
Program Description: 
	This assignment introduces basic C++ program structure and basic constructs
	including comments, basic input/output, type of "int" and some arithmetic 
	operators such as +, -, *, / and %. Two variables are input from keyboard.

Instructions: 
	1. Understand, compile and run this program before you do any change.
	2. In the given program, two variables are divided and multiplied. You are 
		required to implement addition and subtraction operations. Please use
		the given variables, do not declare new ones.
	3. Do not remove any existing statements. Add your code to wherever is marked 
		"Your code below...". 
	4. Make a copy of the given file and rename it with your login, e.g., 
		h1_a_simpleCpp_j_smith.cpp.	
	5. When you are done, submit ONLY your h1_a_simpleCpp_yrlogin.cpp.

References:
	s01a_first_cpp_program.cpp, s01b_basic_cin_cout_operators.cpp

Created: 8/24/2014 by Jin Guo
Updated: 9/3/2014 by Jin Guo. Customized for Harper. 
Updated: 6/4/2021 by Jin Guo. Changed for new semester. Code was simplified.
Updated: 12/30/2023 by Jin Guo. Adapted for this semester.
======================================================================================
*/
#include <iostream> // for cin and cout

using namespace std;

int main()
{
	cout << "=================================================================\n";
	cout << "Harper by Mr. Jin Guo: Assignment #1, Spring 2023\n";
	cout << "Student: Zach Perkins\n\n";
	cout << "This program is to perform some basic arithmetic operations\n";
	cout << "such as addition, subtraction, division and multiplication.\n";
	cout << "=================================================================\n\n";

	int num1;	// for the first number.
	int num2;	// for the second number.

	cout << "Please enter the first integer ==> "; 
	cin >> num1;	// wait for an integer from keyboard
	cout << "Please enter the second integer ==> "; 
	cin >> num2;	// wait for an integer from keyboard
	cout << endl;	// print a new line

	cout << "num1 = " << num1 << "\n";
	cout << "num2 = " << num2 << "\n\n";

	// Divide num1 by num2 to get quotient.
	cout << "Quotient of (num1/num2) = " << num1 / num2 << "\n\n";

	// Divide num1 by num2 to get remainder.
	cout << "Remainder of (num1/num2) = " << num1 % num2 << "\n\n";

	// Multiply num2 and num1.
	cout << "num1 * num2 = " << num1 * num2 << "\n\n";
	
	/*
	Imitating the above code of num1 * num2, add code for "num1 + num2" and 
	"num1 - num2". Please follow the given code style.	
	======================================================
	 <<<<<< Your code below ... >>>>>
	======================================================
	*/
	// Add num1 and num2.
	cout << "num1 + num2 = " << num1 + num2 << "\n\n";
	
	// Subtract num2 from num1.
	cout << "num1 - num2 = " << num1 - num2 << "\n\n";
	cout << endl;
}

/* A Sample Output
================================================================
Harper CSC121-002 by Mr. Jin Guo: Assignment #1, Spring 2023
Student: Zach Perkins

This program is to perform some basic arithmetic operations
such as addition, subtraction, division and multiplication.
================================================================

Please enter the first integer ==> 25
Please enter the second integer ==> 6

num1 = 25
num2 = 6

Quotient of (num1/num2) = 4

Remainder of (num1/num2) = 1

num1 * num2 = 150

num1 + num2 = 31

num1 - num2 = 19

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

