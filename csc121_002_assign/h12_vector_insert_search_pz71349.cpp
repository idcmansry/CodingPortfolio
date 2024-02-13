/*
=====================================================================================
Course: Harper CSC121-002 by Mr. Jin Guo, Spring 2023
Student Name: Zach Perkins

Program Name: Element Insertion, Selection Sort and Binary Search
Program Description:
	This program implements element insertion, selection sort and binary search. 
	An int vector of a constant size is given in this program.

Instructions:
	1. Run h12_JG.out to understand what this program does. Your finished program 
		should perform the same as this one does. Refer to the sample output at 
		the end. Understand the given code before you do any change. 
	2. Don't delete or change any existing code. Just add yours to wherever is 
		marked "Your code below ... ".
	3. Submit only your .cpp file. Name your file properly as usual.

Notes: 
	Subscripts of vector starts with 0. If vector A has N (>= 0) elements, its
	first element is A[0] and the last one is A[N-1]. If you try to access A[N],
	an out-of-bound error are written. Such an error is a subtle bug, which may
	hibernate or manifest itself differently every time you run the program.

References: 
	s09a_vector_basic_operations.cpp -> insertElement()
	s12a_search_int_vector.cpp -> searchBinary_JG()	
	s12b_selection_sort.cpp -> sortSelection_V1()

Created: 11/3/2022 by Jin Guo.
Updated: 3/20/2023 by Jin Guo. The requirements were changed. 
=====================================================================================
*/
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>	// for srand(), rand()
#include <ctime>	// for time() as a seed for srand()

using namespace std;

// Fill in vector A with random numbers.
void fillInVector(vector<int>& A);

// Print vector A with optional message at the beginning.
void outputVector(const vector<int>& A, string msg = "");

// Insert a new element into vector A with a given position.
void insertElement(vector<int>& A, int newElem, size_t pos);

// The straightforward selection sort applied to vector A.
void sortSelection(vector<int>& A);

// Find if a given key is in vector A with binary search.
void binarySearch(const vector<int>& A, int key);

int main()
{
	cout << "============================================================================\n";
	cout << "Harper CSC121-002 by Mr. Jin Guo: Assignment #12, Spring 2023 \n";
	cout << "Student: Zach Perkins\n\n";
	cout << "This program implements Element Insertion, Selection Sort and Binary Search.\n";
	cout << "============================================================================\n\n";

	srand((size_t)time(0)); // seed the rand() by using the time function.

	const int SIZE = 15;

	cout << ">>> Creating vector A of " << SIZE << " elements with random numbers ...\n";
	vector<int> A(SIZE); // All elements of A contain 0.
	fillInVector(A);
	outputVector(A, "[A]: ");

	cout << "\n>>> Inserting a new number 200 at position [15] in vector A ...\n";
	insertElement(A, 200, 15);
	outputVector(A, "[A]: ");

	cout << "\n>>> Inserting a new number 100 at position [5] in vector A ...\n";
	insertElement(A, 100, 5);
	outputVector(A, "[A]: ");

	cout << "\n>>> Sorting vector A ...\n";
	sortSelection(A);
	outputVector(A, "[A]: ");

	cout << "\n>>> Check if 100 is in vector A ...\n";
	binarySearch(A, 100);

	cout << "\n>>> Check if 999 is in vector A ...\n";
	binarySearch(A, 999);

	cout << endl;
}

//------------------------------------------------------------------------------------
void fillInVector(vector<int>& A)
{
	size_t size = A.size();

	for (size_t i = 0; i < size; ++i)
	{
		A[i] = 1 + rand() % (size * 10);
	}
}

void outputVector(const vector<int>& A, string msg)
{
	cout << msg;

	for (int elem : A)
		cout << elem << " ";

	cout << endl;
}

void insertElement(vector<int>& A, int newElem, size_t pos)
{
	if (pos < 0)
	{
		cout << "!!!The given position for new element is negative.\n";
		cout << "\nThis operation is ignored!\n\n";

		return;
	}

	size_t size = A.size();

	if (pos >= size) // insert at back.
	{
		A.push_back(newElem);
		return;
	}

	/*
	=========================================================================
	After the above checking, pos now is in the range of [0, size - 1].
	Add the code which will insert newElem into A at place indicated by pos.
	Please follow the given code style including indent and blank lines.

	<<<<<< Your code below ... >>>>>
	=========================================================================
	*/
	
	int lastElem = A[size - 1];
	A.push_back(lastElem);

	for (size_t i = size - 1; i >= pos; i--) 
	{
		A[i + 1] = A[i]; 
	}
	
	A[pos] = newElem;
}

void sortSelection(vector<int>& A)
{
	size_t size = A.size();

	/*
	=====================================================================
	Using the above variable to add the simple version of selection sort.
	Please follow the given code style including indent and blank lines.

	<<<<<< Your code below ... >>>>>
	=====================================================================
	*/
	
	for (size_t i = 0; i < size - 1; i++)
	{	
		for (size_t j = i + 1; j < size; j++)
		{
			if (A[i] > A[j])
				swap (A[j], A[i]);
		}
	}	
}

void binarySearch(const vector<int>& A, int key)
{
	size_t low = 0;
	size_t high = A.size() - 1;
	size_t mid;

	/*
	=====================================================================
	Using the above variables to add the code of binary search.
	Please follow the given code style including indent and blank lines.

	<<<<<< Your code below ... >>>>>
	=====================================================================
	*/ 
	
	while (low <= high) 
	{
		mid = low + (high - low) / 2;

		if (key == A[mid])
		{
			cout << "Found " << key << " is the element at [" << mid << "]!\n"; 
			return;
		}
		else if (key > A[mid]) 
		{
			low = mid + 1;
		}
		else 
		{
			high = mid - 1;
		}
	}

	cout << key << " is not in the vector!\n";
}

/* A Sample Output
============================================================================
Harper CSC121-002 by Mr. Jin Guo: Assignment #12, Spring 2023
Student: Zach Perkins

This program implements Element Insertion, Selection Sort and Binary Search.
============================================================================

>>> Creating vector A of 15 elements with random numbers ...
[A]: 63 6 135 3 29 124 83 93 136 9 43 114 133 115 73

>>> Inserting a new number 200 at position [15] in vector A ...
[A]: 63 6 135 3 29 124 83 93 136 9 43 114 133 115 73 200

>>> Inserting a new number 100 at position [5] in vector A ...
[A]: 63 6 135 3 29 100 124 83 93 136 9 43 114 133 115 73 200

>>> Sorting vector A ...
[A]: 3 6 9 29 43 63 73 83 93 100 114 115 124 133 135 136 200

>>> Check if 100 is in vector A ...
Found 100 is the element A[9]!

>>> Check if 999 is in vector A ...
999 is not in the vector!

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

