/*
====================================================================================
Course: Harper CSC121-002 by Mr. Jin Guo, Spring 2023
Student Name: Zach Perkins

Program Name: Print The Table of Multiplication
Program Description:
	Use two-level loop controls to print out the table of multiplication for all 
	non-zero single digit operands.

Instructions:
	1. You may use any loop constructs, for-loop, while-loop or do-loop to print
		out the	table. The output of your program should look exactly the same as 
		op2_JG.out. See the sample output at the end of this file. 
	2. In order to align the table perfectly, you need to use "setw()" and
		"left" from <iomanip>. Leave two spaces between columns.
	3. Submit only the .cpp file with your work. Name your file properly as usual.
	
References:
	s03e_embedded_loops_demo.cpp
	s04a_double_output_format.cpp

Created: 9/21/2015 by Jin Guo.
Updated: 2/9/2023 by Jin Guo. Adapted for this semester.
====================================================================================
*/
#include <iostream>
#include <iomanip>	// for setw() and left/right

using namespace std;

int main()
{
	cout << "==================================================================\n";
	cout << "Harper CSC121-002 by Mr. Jin Guo: Optional #2, Spring 2023 \n";
	cout << "Student: Zach Perkins\n\n";
	cout << "A table of times for any non-zero single digit is printed out with\n";
	cout << "some loop constructs such as for-loop, while-loop or do-loop.\n";
	cout << "==================================================================\n\n";

	/*
	================================
	<<<<<< Your code below... >>>>>
	================================
	*/
	
	int rows, cols;
	const int size = 9;		// size of table
	
	cout << left;
	
	for (rows = 1; rows <= size; rows++) 
	{
		for (cols = 1; cols <= rows; cols++)
		{
			cout << cols << "x" << rows << "=";
			/*
			Set width of product to 3 for columns with only single digit products 
			(the first column) and 4 for columns with double digit products.
			*/ 
			cout << setw((cols > 1 ? 4 : 3)) << rows * cols;
		}
		cout << endl;
	}

	cout << endl;
}

/* A Sample Output
==================================================================
Harper CSC121-002 by Mr. Jin Guo: Optional #2, Spring 2023
Student: Zach Perkins

A table of times for any non-zero single digit is printed out with
some loop constructs such as for-loop, while-loop or do-loop.
==================================================================

1x1=1
1x2=2  2x2=4
1x3=3  2x3=6   3x3=9
1x4=4  2x4=8   3x4=12  4x4=16
1x5=5  2x5=10  3x5=15  4x5=20  5x5=25
1x6=6  2x6=12  3x6=18  4x6=24  5x6=30  6x6=36
1x7=7  2x7=14  3x7=21  4x7=28  5x7=35  6x7=42  7x7=49
1x8=8  2x8=16  3x8=24  4x8=32  5x8=40  6x8=48  7x8=56  8x8=64
1x9=9  2x9=18  3x9=27  4x9=36  5x9=45  6x9=54  7x9=63  8x9=72  9x9=81

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

