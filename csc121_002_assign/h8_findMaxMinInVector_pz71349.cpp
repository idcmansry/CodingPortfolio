/*
====================================================================================
Course: Harper CSC121-002 by Mr. Jin Guo, Spring 2023
Student Name: Zach Perkins

Program Name: Exercises on C++ Vector
Program Description:
	This assignment gives you some exercises about <vector>. A vector is given
	and filled in with some random numbers. You need to find the average value, 
	the maximum and minimum elements in the given vector.

Instructions:
	1. Understand and run this program before you do any changes. Also, run 
		h8_JG.out on Unix. Your finished program should perform the same 
		as this one does. 
	2. Your work:
		1) In main(), call findVectorSum() to calculate the average of vector A 
			with two digits preserved after decimal point. 
		2) Define findMaxMinOfVector() after main().
		3) In main(), call findMaxMinOfVector() to print out max and min elements 
			of vector A along with their subscripts. 
	3. Add your code to wherever marked as "Your code below ...". Please do
		not remove any existing code. 
	4. Submit only your .cpp file and name it properly as usual.

Notes: 
	1. You are NOT allowed to use max_element() or min_element() from <algorithm>.
	2. When a statement is too long, break it into two statements or break it
		into two lines.

References: 
	s09a_vector_basic_operations.cpp

Created: 9/8/2007 by Jin Guo
Updated: 2/24/2102 by Jin Guo. Both min and max will be calculated.
Updated: 10/11/2019 by Jin Guo. Finding the average instead of sorting.
Updated: 3/17/2023 by Jin Guo. Adapted for this semester.
=====================================================================================
*/
#include <iostream>	// for cin, cout, fixed
#include <iomanip>	// for setw(), setprecision()
#include <cstdlib>	// for srand(), rand()
#include <ctime>	// for time() as a seed for srand()
#include <vector>
#include <climits>

using namespace std;

// Fill in vector A with random integers.
void fillVectorRandomNums(vector<int>& A);	

// Find and return the sum of vector A.
int findVectorSum(const vector<int>& A);

// Print out vector A.
void printVector(const vector<int>& A);		

// Find maximum and minimum elements along with their subscripts in vector A.
void findMaxMinOfVector(
	const vector<int>& A,		 // the vector to be used.
	int& max, int& min,			 // used to pass out max and min elements.
	size_t& max_i, size_t& min_i // used to pass out subscripts of max and min.
);

int main()
{
	cout << "================================================================\n";
	cout << "Harper CSC121-002 by Mr. Jin Guo: Assignment #8, Spring 2023 \n";
	cout << "Student: Zach Perkins\n\n";
	cout << "This program will find the sum, average, maximum, minimum\n";
	cout << "elements in an integer vector.\n";
	cout << "================================================================\n\n";

	srand((size_t)time(0)); // seed the rand() by using the time function.

	const int SIZE = 12; // size of the vector
	vector<int> A(SIZE); // declare vector A with SIZE and initialized with 0.

	cout << ">>> Generate some random numbers for vector A ...\n";
	fillVectorRandomNums(A);
	printVector(A);

	cout << "\n>>> Finding the sum of all elements in this vector ...\n";
	cout << "The sum is: " << findVectorSum(A) << endl;

	/*
	==========================================================================
	Find the average of vector A with two digits preserved after decimal point.
	<<<<<< Your code below... >>>>>
	==========================================================================
	*/
	cout << "\n>>> Finding the average of this vector ...\n";
	cout << "The average is: " << fixed << setprecision(2) << (double)findVectorSum(A) / A.size() << endl;

	/*
	===========================================================================
	Find maximum and minimum elements in A by calling findMaxMinOfVector() with
	the declared variable below.
	<<<<<< Your code below... >>>>>
	===========================================================================
	*/
	int max{ 0 }, min{ 0 };			// for maximum and minimum elements.
	size_t max_i{ 0 }, min_i{ 0 };	// for subscripts of maximum and minimum.
	
	cout << "\n>>> Finding the maximum and minimum values in this vector ...\n";
	findMaxMinOfVector(A, max, min, max_i, min_i);
	
	cout << "The maximum element is: A[" << max_i << "] = " << max << endl;
	cout << "The minimum element is: A[" << min_i << "] = " << min << endl;
	
	cout << endl;
}

//===============================================================================
void fillVectorRandomNums(vector<int>& A)
{
	size_t SIZE = A.size();

	for (size_t i = 0; i < SIZE; ++i)
	{
		A[i] = 1 + rand() % (SIZE * 10);
	}
}

int findVectorSum(const vector<int>& A)
{
	int sum = 0;
	for (size_t i = 0; i < A.size(); i++)
		sum = sum + A[i];

	return sum;
}

void printVector(const vector<int>& A)
{
	cout << "Elem#" << setw(8) << "Value" << endl;
	cout << "~~~~~" << setw(8) << "~~~~~" << endl;

	for (size_t i = 0; i < A.size(); ++i)
	{
		cout << setw(5) << i << setw(8) << A[i] << endl;
	}
}

/*
==========================================================================
Define the following function.	
Hint: Assume the first element is the max or min at the beginning. You may 
	use any loop controls, but it's more natural to use for-loop here. 		

<<<<<< Your code below... >>>>>
==========================================================================
*/
void findMaxMinOfVector(const vector<int>& A,
	int& max, int& min, size_t& max_i, size_t& min_i)
{
	max = min = A[0];
	max_i = min_i = 0;
	

	for (size_t i = 1; i < A.size(); ++i)
	{
		if (A[i] > max)
		{
			max = A[i];
			max_i = i;
		}
		if (A[i] < min)
		{
			min = A[i];
			min_i = i;
		}
	}
}

/* A Sample Output
================================================================
Harper CSC121-002 by Mr. Jin Guo: Assignment #8, Spring 2023
Student: Zach Perkins

This program will find the sum, average, maximum, minimum
elements in an integer vector.
================================================================

>>> Generate some random numbers for vector A ...
Elem#   Value
~~~~~   ~~~~~
    0      92
    1      20
    2       2
    3      48
    4     102
    5      18
    6       8
    7      40
    8     117
    9     116
   10      41
   11      11

>>> Finding the sum of all elements in this vector ...
The sum is: 615

>>> Finding the average of this vector ...
The average is: 51.32

>>> Finding the maximum and minimum values in this vector ...
The maximum element is: A[8] = 117
The minimum element is: A[2] = 2

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

