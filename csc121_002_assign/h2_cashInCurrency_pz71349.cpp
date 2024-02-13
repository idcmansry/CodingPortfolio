/*
==================================================================================
Course: Harper CSC121-002 by Mr. Jin Guo, Spring 2023
Student Name: Zach Perkins

Program Name: An Auto Cashier
Program Description:
	This program is for you to exercise selection-statements. You should
	understand the difference between "int" and "double". The input check will
	be converted into hundred-bills, twenty-bills, ten-bills, five-bills, dollars,
	quarters, dimes, nickels and cents.

Instructions:
	1. First, read, compile and run the given program without any change.
	2. Run h2_JG.out a couple of times. When you're done, your program should 
		perform the same as this one does. Refer to the sample output at the end.	
	3. The given code has done the "dollar part". You need to implement the 
		"cent part", i.e., to turn the remaining cents into quarters, dimes, 
		nickels and cents.
	4. Add your code to wherever is marked "Your code below...". Do not remove 
		any existing statements. The given variables should be re-used whenever 
		possible.
	5.  Make a copy of the given file and rename it with your login, e.g.,
		h2_cashInCurrency_j_smith.cpp. 
	6. Submit ONLY your h2_cashInCurrency_yrlogin.cpp.

Notes: 
	In a boolean expression, any non-zero value is treated as true and 0 as false.

References:
	s02a_if_else_relational_operators.cpp
	s02b_switch_case_statement.cpp
	s02c_logic_operators_demo.cpp
	s02d_relational_logic_operators.cpp

Created: 1/31/2012 by Jin Guo.
Updated: 9/11/2014 by Jin Guo. Customized for Harper.
Updated: 12/30/2022 by Jin Guo. Adapted for this semester. 
		Significant change. Removed code of casting.
==================================================================================
*/
#include <iostream>

using namespace std;

int main()
{
	cout << "===============================================================\n";
	cout << "Harper CSC121-002 by Mr. Jin Guo: Assignment #2, Spring 2023 \n";
	cout << "Student: Zach Perkins\n\n";
	cout << "This program will cash the amount of money into bills of 100,\n"; 
	cout << "20, 10, 5 and 1 dollars and coins of quarters, dimes, nickels\n";
	cout << "and cents.\n";
	cout << "===============================================================\n\n";

	int dollars;	// store the dollar part as int from the cashAmount
	int cents;		// store the cent part as int from the cashAmount
	cout << "Input how many dollars (e.g., 456) == > ";
	cin >> dollars;
	cout << "Input how many cents (e.g., 67 or 167) == > ";
	cin >> cents;

	dollars = dollars + cents / 100;
	cents = cents % 100;

	cout << "\n>>> You have asked to cash " << dollars << " dollars and "
		<< cents << " cents.\n\n";

	int hundreds = 0;	// for the number of $100 bills
	int twenties = 0;	// for the number of $20 bills
	int tens = 0;		// for the number of $10 bills
	int fives = 0;		// for the number of $5 bills

	if (dollars > 0)
	{
		if (dollars >= 100)
		{
			hundreds = dollars / 100;
			dollars = dollars % 100;
		}
		if (dollars >= 20)
		{
			twenties = dollars / 20;
			dollars = dollars % 20;
		}
		if (dollars >= 10)
		{
			tens = dollars / 10;
			dollars = dollars % 10;
		}
		if (dollars >= 5)
		{
			fives = dollars / 5;	// or: fives = 1
			dollars = dollars % 5;	// or: dollars = dollars - 5
		}

		/**
		Print the results. A certain bill value will be skipped
		if its value is zero.
		*/
		cout << ">>> Please count, you have \n";
		if (hundreds != 0) // or if (hundreds)
			cout << hundreds << " one hundred bill(s), \n";
		if (twenties != 0)
			cout << twenties << " twenty bill(s), \n";
		if (tens != 0)
			cout << tens << " ten bill(s), \n";
		if (fives != 0)
			cout << fives << " five bill(s) and\n";

		if (dollars != 0)
			cout << "and " << dollars << " dollar bill(s). \n\n";
		else
			cout << "and 0 dollar bill(s).\n\n";
	}

	/*
	Imitating the above code for "dollar part" of calculating dollar bills,
	add your code to conver "cents" into quarters, dimes, nickels and cents.
	=======================================================================
	<<<<<< Your code below ... >>>>>
	=======================================================================
	*/
	int quarters = 0;	// for the number of quarters
	int dimes = 0;		// for the number of dimes
	int nickels = 0;	// for the number of nickels

	if (cents > 0)
		{
			if (cents >= 25)
			{
				quarters = cents / 25;
				cents = cents % 25;
			}
			if (cents >= 10)
			{
				dimes = cents / 10;
				cents = cents % 10;
			}
			if (cents >= 5)
			{
				nickels = cents / 5;
				cents = cents % 5;
			}
			
			cout << ">>> Please count, you have \n";
			if (quarters != 0) // or if (hundreds)
				cout << quarters << " quarter(s), \n";
			if (dimes != 0)
				cout << dimes << " dime(s), \n";
			if (nickels != 0)
				cout << nickels << " nickel(s), \n";

			if (cents != 0)
				cout << "and " << cents << " cent(s). \n\n";
			else
				cout << "and 0 cent(s).\n\n";
		}


	cout << endl;
}

/* A Sample Output
===============================================================
Harper CSC121-002 by Mr. Jin Guo: Assignment #2, Spring 2023
Student: <Your Name>

This program will cash the amount of money into bills of 100,
20, 10, 5 and 1 dollars and coins of quarters, dimes, nickels
and cents.
===============================================================

Input how many dollars (e.g., 456) == > 456
Input how many cents (e.g., 67 or 167) == > 167

>>> You have asked to cash 457 dollars and 67 cents.

>>> Please count, you have
4 one hundred bill(s),
2 twenty bill(s),
1 ten bill(s),
1 five bill(s) and
and 2 dollar bill(s).

>>> Plus you have
2 quarter(s),
1 dime(s),
1 nickel(s),
and 2 cent(s).

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

