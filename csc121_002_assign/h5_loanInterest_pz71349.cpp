/*
==================================================================================
Course: Harper CSC121-002 by Mr. Jin Guo, Spring 2023
Student Name: Zach Perkins

Program Name: Compound Interest Calculation
Program Description:
	This program calculates and lists each year's balance for a compound
	interest of a loan.

Instructions:
	1. Understand, compile and run the given program before you do any changes.
	2. Change those initial values by asking user to input them from keyboard.
		Keep the code of getting inputs in main() function. 
	3. Move the code (lines 74-89) of calculating compound interest and printing
		the balance table into the function definition after main().
	4. Your finished program should perform the same as h5_JG.out does, including 
		output and prompts for input. Refer to the sample output.
	5. Submit only your .cpp file with your change. Name your file properly
		as usual.

Notes:
	1. In a function prototype, parameter name(s) can be differnent or the same
		as the real arguments in the client code. 
	2. Library functions used:
		cout << fixed;				// display numbers in fixed format.
		cout << setw(5);			// set a field width of 5 spaces.
		cout << setprecision(2);	// preserve 2 digits after decimal point.
		pow(3, 2);					// pow(3.0, 2.0) = 3.0^2.0 = 9.0;

References: 
	CS Videos YT -> Some Interesting Algorithms -> Compound Interest Formula

Created: 1/31/2012 by Jin Guo.
Updated: 10/13/2020 by Jin Guo. Changed for new semester.
Updated: 12/30/2023 by Jin Guo. Adapted for this semester.
==================================================================================
*/
#include <iostream>	// for cin, cout, fixed
#include <iomanip>	// for setw(), setprecision()
#include <cmath>	// for pow()

using namespace std;

/**
The following function calculates and lists balance of each year.

@param p: the given principal.
@param r: the given rate, 5 means 5%.
@param y: how many years.
*/
void interestCalculate(double p, double r, int y);

int main()
{
	cout << "=============================================================\n";
	cout << "Harper CSC121-002 by Mr. Jin Guo: Assignment #5, Spring 2023 \n";
	cout << "Student: Zach Perkins\n\n";
	cout << "This program will do compound interest calculation.\n"; 
	cout << "=============================================================\n\n";

	double principal;	// the principal.
	double rate;			// interest rate, 5 means 5% interest. 
	int years;				// how many years.
	
	cout << "Input the principal (e.g., 1000) ==> ";
	cin >> principal;
	
	cout << "Input the interest rate n% (e.g., 5) ==> ";
	cin >> rate;
	
	cout << "Input how many years (e.g., 10) ==> ";
	cin >> years;
	cout << endl;

	interestCalculate(principal, rate, years);

	cout << endl;
} 

void interestCalculate(double p, double r, int y)
{
	// Move the code of printing balance table form main() to here below.
	cout << ">>> Here is the balance table based on your inputs:\n";

	cout << fixed << setprecision(2); // set floating-point number format
	cout << "Principal = $" << p
		<< ", Interest = " << r << "%"
		<< ", Years = " << y << "\n";
	cout << ".......\n\n";

	// Display the header
	cout << "Year\t" << "Balance" << endl;
	cout << "~~~~\t" << "~~~~~~~" << endl;

	cout << fixed << setprecision(2); // set floating-point number format

	for (int i = 1; i <= y; ++i)
	{
		double balance; // for balance at end of each year

		// Calculate new balance for a specific year
		balance = p * pow(1.0 + r / 100.0, i);

		// Display the year and the amount.
		cout << right << setw(4) << i << "\t" << balance << endl;
	}
}

/* A Sample Output
=============================================================
Harper CSC121-002 by Mr. Jin Guo: Assignment #5, Spring 2023
Student: Zach Perkins

This program will do compound interest calculation.
=============================================================

Input the principal (e.g., 1000) ==> 1000
Input the interest rate n% (e.g., 5) ==> 5
Input how many years (e.g., 10) ==> 10

>>> Here is the balance table based on your inputs:
Principal = $1000.00, Interest = 5.00%, Years = 10
.......

Year    Balance
~~~~    ~~~~~~~
   1    1050.00
   2    1102.50
   3    1157.63
   4    1215.51
   5    1276.28
   6    1340.10
   7    1407.10
   8    1477.46
   9    1551.33
  10    1628.89

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

