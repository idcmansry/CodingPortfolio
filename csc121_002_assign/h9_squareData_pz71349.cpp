/*
==========================================================================================
Course: Harper CSC121-002 by Mr. Jin Guo, Spring 2023
Student Name: Zach Perkins

Program Name: Find Area and Perimeter of a Square
Program Description:
	This program asks user to input a side to define a square and calculates area
	and perimeter of this square. 
		
Instructions:
	1. This is the first time you have a chance to write a whole program. Please follow
		the given code style of the previous program assignments.
	2. Please read the following requirements carefully. Try to imitate the sample output
		closely, including the prompts and blank lines.
	3. Submit only your .cpp file and name it properly as usual.

Requirements:
	1. Define a function which can calculate area and perimeter of a square. It
		should take one parameter passing-by-value for side, and a second one 
		passing-by-reference for area and the third one passing-by-reference for 
		perimeter. This function should be called in main() to find area and
		perimeter based on the input side.
	2. User is allowed to repeat for another input until she/he chooses to quit.
	3. Make sure user to input a double or int and it is not negative. This is optoinal.
		To make things easier, You may ignore this at the beginning and implement it 
		as the last step. You may define a function to implement this.

References:
	s03c_loop_control_by_yes.cpp
	s03d_securing_input.cpp
	s06a_function_basics.cpp
	
Created: 3/6/2023 by Jin Guo
==========================================================================================
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <climits>

using namespace std;

void findSquare(double side, double& area, double& perimeter);

int main()
{
	cout << "==================================================================\n"
		 << "Harper CSC121-002 by Mr. Jin Guo: Assignment #9, Spring 2023\n"
		 << "Student: Zach Perkins\n\n"

		 << "This program asks user to input a side to define a square and\n"
		 << "calculates area and perimeter of this square.\n"
		 << "==================================================================\n";
	
	string str;
	double side, area, perimeter;
	string loop = "Y";
	
	while (loop == "Y" || loop == "y") 
	{
		cout << "\nPlease enter a square size >= 0.0 (e.g., 2.5 or 25) ==> ";
		cin >> str;
		cin.ignore(INT_MAX, '\n');
		
		try
		{
			side = stod(str);
		}
		catch (...)
		{
			cout << "This is not a number! Try again ...\n";
			continue;
		}
		
		if (side < 0)
		{
			cout << "The number must >= 0.0! Try again ...\n";
			continue;
		}
		
		findSquare(side, area, perimeter);
		
		cout << fixed << setprecision(2);
		cout <<	"\n>>> Its area is: " << area
			 << "\n>>> Its perimeter is: " << perimeter

			 << "\n\n=================================================="
			 << "\nDo you want to do this again?"
			 << "\n(y/Y to continue) ==> ";
		cin >> loop;
		cin.ignore(INT_MAX, '\n');
	}
	
	cout << endl;
}

void findSquare(double side, double& area, double& perimeter)
{
	area = side * side;
	perimeter = 4.0 * side;
}

/* A Sample Output
==================================================================
Harper CSC121-002 by Mr. Jin Guo: Assignment #9, Spring 2023
Student: Zach Perkins

This program asks user to input a side to define a square and
calculates area and perimeter of this square.
==================================================================

Please enter a square size >= 0.0 (e.g., 2.5 or 25) ==> abc
This is not a number! Try again ...

Please enter a square size >= 0.0 (e.g., 2.5 or 25) ==> -2.5
The number must >= 0.0! Try again ...

Please enter a square size >= 0.0 (e.g., 2.5 or 25) ==> 2.5

>>> Its area is: 6.25
>>> Its perimeter is: 10.00

==================================================
Do you want to do this again?
(y/Y to continue) ==> y

Please enter a square size >= 0.0 (e.g., 2.5 or 25) ==> 25

>>> Its area is: 625.00
>>> Its perimeter is: 100.00

==================================================
Do you want to do this again?
(y/Y to continue) ==> no

*/

