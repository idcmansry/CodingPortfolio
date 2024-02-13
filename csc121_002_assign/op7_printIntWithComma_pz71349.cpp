/*
============================================================================================
Course: Harper CSC121-002 by Mr. Jin Guo, Spring 2023
Student Name: Zach Perkins

Program Name: Print a Large Integer with Comma
Program Description:
	This program will print a large number with comma, e.g., 
	123 --> 123
	-1234 --> -1,234
	1234005 --> 1,234,005
	-123456789 --> -123,456,789

Instructions:
	1. Run op7_JG.out a couple of times. When you are done, your program should perform 
		the same as this one does. Your output should imitate the sample output closely.
	2. You are required to define a function called printNumWithComma, either recursively
		or iteratively (i.g.,use loop contruct), which takes one parameter and returns 
		nothing.
	3. Submit only your .cpp file. Name your file properly as usual.

Notes: 
	1. Your program should be able to print both positive and negative numbers correctly.
	2. You may need to use setw() and setfill() for numbers such as 1234005 --> 1,234,005.
	3. Use "long long int" instead of "int" for input value.


Created: 3/8/2023 by Jin Guo. 
============================================================================================
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <climits>

using namespace std;

void printNumWithComma(long long int Num);

int main()
{
	cout << "===============================================================\n";
	cout << "Harper CSC121-002 by Mr. Jin Guo: Optional #7, Spring 2023\n";
	cout << "Student: Zach Perkins\n\n";
	cout << "This program will print a large number with comma, e.g.,\n";
	cout << "1234 --> 1,234; -1234567 --> -1,234,567; 1234005 --> 1,234,005\n";
	cout << "===============================================================\n";
	
	long long int initial;
	string loop;
	
	do
	{
		cout << "\nPlease input an integer ==> ";
		cin >> initial;
		cin.ignore(INT_MAX,'\n');
		printNumWithComma(initial);
		
		cout << "\n-----------------------------------------------------\n";
		cout << "Try this again? (y/Y to continue, n/no to quit) ==> ";
		cin >> loop;
	} while (loop == "y" || loop == "Y");
}

void printNumWithComma(long long int Num)
{
	string Numstr = to_string(Num);
	if (Numstr[0] == '-')
	{
		cout << "-";
		Numstr.erase(0, 1);
	}
	
	for (size_t idx = 0; idx < Numstr.length(); idx++)
	{
		cout << Numstr[idx];
		if ((Numstr.length() - idx - 1) % 3 == 0 && idx + 1 != Numstr.length())
		{
			cout << ",";
		}
	}
	cout << endl;
}

/* A Sample Output
===============================================================
Harper CSC121-002 by Mr. Jin Guo: Optional #7, Spring 2023
Student: Zach Perkins

This program will print a large number with comma, e.g.,
1234 --> 1,234; -1234567 --> -1,234,567; 1234005 --> 1,234,005
===============================================================

Please input an integer ==> 123
123

-----------------------------------------------------
Try this again? (y/Y to continue, n/no to quit) ==> y

Please input an integer ==> 1234567
1,234,567

-----------------------------------------------------
Try this again? (y/Y to continue, n/no to quit) ==> y

Please input an integer ==> -1234567
-1,234,567

-----------------------------------------------------
Try this again? (y/Y to continue, n/no to quit) ==> y

Please input an integer ==> 1234005
1,234,005

-----------------------------------------------------
Try this again? (y/Y to continue, n/no to quit) ==> n

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

