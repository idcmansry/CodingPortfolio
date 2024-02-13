/*
=====================================================================================
Course: Harper CSC121-002 by Mr. Jin Guo, Spring 2023
Student Name: Zach Perkins

Program Name: Algorithm Analysis
Program Description:
	This program implements some sorting algorithms on an int vector. User is
	prompted to	input the size of a vector and then to decide the vector is either
	random or in order. This program will generate an int vector of the given size 
	and then sort it. The time is measured for each sorting algorithm so user can 
	compare the efficiency of different algorithms with different data sizes and 
	different data patterns (ordered or not).

Instructions:
	1. Try to understand the program as much as you can. You may not be able to 
		understand all the given functions, but you are required to understand the
		the main structure of the given code. Compile and run the given program. 
		Don't remove any existing code, just add yours.	Add your code wherever is 
		marked "Your code below... ".
	2. Run the executable h13_JG.out and your finished program should perform the 
		same as this one does.	
	3. You are required to add Bubble-Sort (write your own or search on Internet) 
		in the given context. You may add more sorting algorithms if you want to.
	4. Please follow the code style and conventions in the given program.
	5. Submit only your .cpp file and name it properly as usual.

Notes:
	1. size_t is an alias of "unsigned int". It's used for size and position.
	2. swap() is defined in standard library <algorithm>.
	3. sort() from C++ library uses IntroSort, which is a combination of QuickSort, 
		HeapSort and InsertionSort.
	4. There are many versions of Bubble-Sort. The one you choose should be able to
		stop sorting when the vector is already in order. You may need to customize
		the code you borrowed to fit in the given program. Do necessary improvements
		and fixes if needed.

References:		
	1. On Blackboard: CS Videos YT -> Sorting Algorithms 
		-> Bubble-Sort with Hungarian folk dance. 
	2. Here are two reference links to Bubble-Sort: 
		1) https://stackoverflow.com/questions/30963204/c-vector-bubble-sort/30963237
			This one uses c++ vector but has an error and redundant logic.
		2) https://favtutor.com/blogs/bubble-sort-cpp
			This one has no redundant logic but it uses C-array. You need to adjust 
			it to C++ vector. 

Created: 3/9/2010 by Jin Guo
Updated: 4/17/2016 by Jin Guo. Added merge sort for this semester.
Updated: 5/2/2022 by Jin Guo. Adapted for this semester. Improved printIntVector().
			Give one more link to Bubble-Sort.
Updated: 4/24/2023 by Jin Guo. Removed selection sort. Other minor improvements.
=====================================================================================
*/
#include <iostream>
#include <vector>
#include <string>		// to_string()
#include <iomanip>		// for setw(), setprecision()
#include <cstdlib>		// for srand(), rand()
#include <ctime>		// for CLOCKS_PER_SEC, difftime() and time() 
#include <algorithm>	// for swap(), random_shuffle() and sort()
#include <climits>		// for INT_MAX

using namespace std;

// Define the function type for sorting algorithm
using SortAlgorithmX = void(*)(vector<int>& A);
//typedef void(*SortAlgorithmX)(vector<int>& A); // the old way

// Input a vector size which is greater than 1.
int getVectorSize();

// Generates ordered integers for an int vector
void fillInVector(vector<int>& A);

// Measure the time for a passed-in sorting algorithm
void sortAlgorithmX_timeSpent(SortAlgorithmX sortAlgorithmX, vector<int>& A);

// Run all implemented sorting algorithms
void sortManyAlgorithms(const vector<int>& A);

// Print out a division line with a given char.
void printDivisionLine(int length, char aChar);

// Print out the vector
void printIntVector(const vector<int>& A);

// Copy vector A into vector R, same as R = A or R.assign(A.begin(), A.end()).
void copyIntVector(const vector<int>& A, vector<int>& R);

/*
===========================================
Function prototypes of sorting algorithms
===========================================
*/
// The sort function sort() from C++ library <algorithm>.
void sortCplusplusLibSort(vector<int>& A);

// The Selection-Sort
void sortSelection(vector<int>& A);

// Insertion-Sort
void sortInsertion(vector<int>& A);

// Merge-Sort
void merge2HalfsOfVector(vector<int>& A, size_t from, size_t mid, size_t to);
void mergeSort(vector<int>& A, size_t from, size_t to);
void sortMerge(vector<int>& A) { mergeSort(A, 0, A.size() - 1); }

/*
==========================================================
You need to define these functions after main().
<<<<<< Your code below ... >>>>>
==========================================================
*/
// The Bubble-Sort
void sortBubble(vector<int>& A);

// More sorting functions below if you want to ...

int main()
{
	cout << "===================================================================\n";
	cout << "Harper CSC121-002 by Mr. Jin Guo: Assignment #13, Spring 2023\n";
	cout << "Student: Zach Perkins\n\n";
	cout << "This program sorts a vector with different sorting algorithms.\n";
	cout << "====================================================================\n";

	string choice;
	do 
	{
		cout << "\n>>>>>> Let's play with some sorting algorithms ... >>>>>>\n\n";

		int SIZE = getVectorSize();

		vector<int> A(SIZE);	// construct vector A for the input size
		fillInVector(A);		// fill A with values in order.

		char c;		
		cout << "\nDo you want the vector in random order? (y/n) ==> ";
		cin >> ws >> c;
		cin.ignore (INT_MAX, '\n');	
			
		if (c == 'y')			// shuffle A so data is in random.
			random_shuffle(A.begin(), A.end()); 

		sortManyAlgorithms(A);

		cout << "\n=================================================================\n";
		cout << "Do you want to play this again? y(es) or n(o) ==> ";
		cin >> ws; // skip leading white spaces.
		getline(cin, choice);	
	} while (!(choice[0] == 'N' || choice[0] == 'n'));

	cout << "\n=== Thanks for using this program! See you next time! ===\n\n";
}

/* 
============================================
Definitions of functions
============================================
*/
int getVectorSize()
{
	int N;

	while (true)
	{
		cout << "Please enter vector size N > 1 (e.g., 100) ==> ";
		cin >> N;

		if (cin.fail())
		{
			cin.clear(); // clear tags of cin.
			cin.ignore(INT_MAX, '\n'); // clear the input buffer.
			cout << "\nThis is not an integer! Try again ...\n";
		}
		else
		{
			cin.ignore(INT_MAX, '\n'); // clear the input buffer.

			if (N <= 1)
				cout << "\nSize N must be greater than 1! Try again ...\n";
			else
				break;
		}
	};

	return N;
}

void fillInVector(vector<int>& A)
{
	for (size_t i = 0; i < A.size(); ++i)
		A[i] = i + 1;
}

void sortAlgorithmX_timeSpent(SortAlgorithmX sortAlgorithmX, vector<int>& A)
{
	time_t time_start, time_end;     // record wall clock time elapsed.
	clock_t clock_begin, clock_stop; // record CPU time used by the operation.

	time(&time_start);	
	clock_begin = clock();	
	
	sortAlgorithmX(A);

	clock_stop = clock();
	time(&time_end);	

	double user_time = (clock_stop - clock_begin) / (double)CLOCKS_PER_SEC;
	double wall_time = difftime(time_end, time_start);

	cout << fixed << setprecision(4);
	cout << "--------------------------------------\n";
	cout << "|     CPU time used: " << user_time << " seconds.\n";
	cout << "| Wall clock passed: " << wall_time << " seconds.\n";
	cout << "--------------------------------------\n";
}

void sortManyAlgorithms(const vector<int>& A)
{
	vector<int> R; 
	
	cout << "\nThe original vector A: \n";
	printIntVector(A);

	cout << "\nCopy vector A into vector R ...\n";
	copyIntVector(A, R);
	cout << ">>>> Using <<< C++ Lib-Sort >>> algorithm from library <algorithm> ...\n";
	sortAlgorithmX_timeSpent(sortCplusplusLibSort, R); // sorting R in place.
	cout << "\nAfter sorting with sortCplusplusLibSort, the reult R: \n";
	printIntVector(R);

	cout << "\nCopy vector A into vector R ...\n";
	copyIntVector(A, R);
	cout << ">>>>> Using <<< Merge-Sort >>> algorithm ...\n";
	sortAlgorithmX_timeSpent(sortMerge, R); // sorting R in place.
	cout << "\nAfter sorting with sortMerge, the reult R: \n";
	printIntVector(R);	

	cout << "\nCopy vector A into vector R ...\n";
	copyIntVector(A, R);
	cout << ">>>> Using <<< Insertion-Sort >>> algorithm ...\n";
	sortAlgorithmX_timeSpent(sortInsertion, R); // sorting R in place.
	cout << "\nAfter sorting with sortInsertion, the reult R: \n";
	printIntVector(R);

	cout << "\n===========================================================";
	cout << "\n<<<<<<<<< I added the following sorting algorithms >>>>>>>>>";
	cout << "\n===========================================================\n";
	/*
	==========================================================
	<<<<<< Your code below... >>>>>
	==========================================================
	*/
	cout << "\nCopy vector A into vector R ...\n";
	copyIntVector(A, R);
	cout << ">>>> Using <<< Bubble-Sort >>> algorithm ...\n";
	sortAlgorithmX_timeSpent(sortBubble, R); // sorting R in place.
	cout << "\nAfter sorting with sortBubble, the reult R: \n";
	printIntVector(R);

}

void copyIntVector(const vector<int>& A, vector<int>& R)
{
	size_t size = A.size();

	if (size != R.size())
		R.resize(size);

	for (size_t i = 0; i < size; ++i)
		R[i] = A[i];
}

void printDivisionLine(int length, char aChar)
{
	for (int i = 0; i < length; ++i)
		cout << aChar;

	cout << endl;
}

void printIntVector(const vector<int>& A)
{
	size_t size = A.size();

	const int MAX_COLUMNS = 66;
	const size_t PRINTED_SIZE = 20;
	const int NUM_WIDTH = to_string(size).size() + 2;
	const int ITEMS_PER_LINE = MAX_COLUMNS / NUM_WIDTH;

	size_t tmp_size = (size <= PRINTED_SIZE) ? size : PRINTED_SIZE;

	if (size > PRINTED_SIZE && size <= 2 * PRINTED_SIZE)
	{
		cout << "(The vector of " << size << " is a little large, \n";
		cout << "only first " << PRINTED_SIZE << " elements are printed out!)\n";
	}
	else if (size > 2 * PRINTED_SIZE)
	{
		cout << "(The vector of " << size << " is too large, \n"
			<< "only first and last " << PRINTED_SIZE << " elements are printed out!)\n";
	}

	printDivisionLine(MAX_COLUMNS, '-');

	for (size_t i = 0; i < tmp_size; ++i) // print the first 20 elements.
	{
		if (i != 0 && i % ITEMS_PER_LINE == 0)
			cout << "\n";

		cout << setw(NUM_WIDTH) << fixed << A[i];
	}
	cout << "\n";

	if (size <= PRINTED_SIZE) // done.
	{
		printDivisionLine(MAX_COLUMNS, '-');
		return;
	}

	printDivisionLine(MAX_COLUMNS, '.');

	if (size > 2 * PRINTED_SIZE) // print the last 20 elements.
	{
		for (size_t i = size - PRINTED_SIZE, k = 0; i < size; ++i, ++k)
		{
			if (k != 0 && k % ITEMS_PER_LINE == 0)
				cout << "\n";

			cout << setw(NUM_WIDTH) << fixed << A[i];
		}
	}
	cout << "\n";

	printDivisionLine(MAX_COLUMNS, '-');
}

/*
============================================
Sorting algorithms
============================================
*/
void sortCplusplusLibSort(vector<int>& A)
{
	sort(A.begin(), A.end());
}

void sortInsertion(vector<int>& A)
{
	size_t size = A.size();

	for (size_t k = 1; k < size; ++k)
	{
		int temp = A[k];
		size_t j = k;

		while (j > 0 && A[j - 1] > temp)
		{
			A[j] = A[j - 1];
			--j;
		}

		if (j != k)
			A[j] = temp;
	}
}

void merge2HalfsOfVector(vector<int>& A, size_t from, size_t mid, size_t to)
{
	size_t n = to - from + 1;	// size of the range to be merged.
	vector<int> B(n);			// merge both halves into a vector B.

	size_t i1 = from;			// start index in the first half. 
	size_t i2 = mid + 1;		// start index in the second half. 
	size_t j = 0;				// current position in B. 

	/**
	Compare A[i1] and A[i2] until either of i1 and i2 reaches the end,
	move the smaller one into B.
	*/
	while (i1 <= mid && i2 <= to)
	{
		if (A[i1] < A[i2])
			B[j++] = A[i1++];
		else
			B[j++] = A[i2++];
	}

	while (i1 <= mid)	// copy any remaining entries of the first half.
		B[j++] = A[i1++];

	while (i2 <= to)	// copy any remaining entries of the second half.
		B[j++] = A[i2++];

	for (j = 0; j < n; ++j) // copy back from the temporary vector.
		A[from + j] = B[j];
}

void mergeSort(vector<int>& A, size_t from, size_t to)
{
	if (from == to)
		return;

	size_t mid = (from + to) / 2;

	mergeSort(A, from, mid);
	mergeSort(A, mid + 1, to);
	merge2HalfsOfVector(A, from, mid, to);
}

/*
==========================================================
<<<<<< Your code below... >>>>>
==========================================================
*/

void sortBubble(vector<int>& A)
{
	bool sort = true;
	while (sort)
	{
		sort = false;
		for (int i = 0; i <= A.size()-1; i++)
		{
			if (A[i] > A[i+1])
			{
				swap(A[i],A[i+1]);
				sort = true;
			}
		}
	}
}

/*
************************************************
* (C) Copyright - by Jin Guo
*
* This program is free for my class students.
* For any other purpose of using this program,
* please ask for permission by sending email to:
* taiji.guo@gmail.com
************************************************
*/

