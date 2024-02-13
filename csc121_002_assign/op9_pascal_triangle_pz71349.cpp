/*
====================================================================================
Course: Harper CSC121-002 by Mr. Jin Guo, Spring 2023
Student Name: Zach Perkins

Program Name: Print Pascal's Triangle 
Program Description: 
	The pattern of the list of coefficients of (a+b)^n is called Pascal's Triangle.
	Here is an example for (a+b)^5,
				1 ----------------- level 0
			  1   1 --------------- level 1
			1   2   1 ------------- level 2
		  1   3   3   1 ----------- level 3
		1   4   6   4   1 --------- level 4
	  1   5   10  10  5   1 ------- level 5

	This program prints a Pascal's Triangle by one input to indicate how many levels.
	You may use two-level loops and a two-dimensional vector<int> variable to implement
	the main algorithm within printPascalTriangle().

Instructions: 
	1. Run op9_JG.out to see how the program performs. See the sample output at the 
		end of this program. Your program should perform the same as this one does.
	2. Please follow the given code style and conventions. Your program should be 
		organized with functions. I suggested a program frame with the following 
		functions. You may ignore my suggestions and create your own frame. 

		int getLevel_N(); // get the level number for a Pascal Triangle.	
		size_t findWidth(int N); // return the width for printing a number. 	
		size_t combination(size_t n, size_t k);// find combination k from n. 	
		void printPascalTriangle(int N); // Print Pascal Triangle. N >= 0.	
	3. Submit only your .cpp file. Name your file properly as usual.

Notes: 
	1. Here is a good website to understand Pascal's Triangle:
		https://www.mathsisfun.com/pascals-triangle.html
	2. If C(n, k) represents the number of combinations of taking k items out of n,
		the formula below can be used:
		C(n, k) = n! / (k! * (n - k)!) = (n(n-1)(n-2)..(n-k+2)(n-k+1)) / k!
	3. You may define a function to find the width for each number. Within this 
		function, you may use the above formula to find the maximum number. 
		In order to make output looks symmetric, the width should be an even number.
	
Created: 8/12/2020 by Jin Guo.
Updated: 11/10/2020 by Jin Guo. Some improvements with secure input and uint64_t.
		Add three functions.
Updated: 3/22/2023 by Jin Guo. Significant improvements.
====================================================================================
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

void makePascalTriangle(vector<vector<int>>& triangle, const int& size, int line);
int findWidth(const vector<vector<int>>& triangle, const int& size);
void printPascalTriangle(vector<vector<int>>& triangle, const int& size);

int main()
{
	cout << "=====================================================================\n"
		 << "Harper CSC121-002 by Mr. Jin Guo: Optional #9, Spring 2023\n"
		 << "Student: Zach Perkins\n\n"

		 << "This program will print out a Pascal Triangle with a fixed size.\n"
		 << "The size is input from keyboard and it's suggested that the size\n"
		 << "be <= 20 or the result will be too large to be displayed on screen.\n"
		 << "=====================================================================\n\n";
	char loop = 'y';
	while(loop == 'y' || loop == 'Y')
	{
		int size;
		cout << "Please input N for (a+b)^N (N >= 0, e.g., 6) ==> ";
		cin >> size;
		vector<vector<int>> triangle(size + 1);
		for (int idx = 0; idx <= size; idx++)
		{
			triangle[idx] = vector<int>(size + 1, 0);
			triangle[idx][size] = 1;
		}
		printPascalTriangle(triangle, size);
		cout << "-------------------------------------------------------\n"
			 << "Do you want to do this again? (y/Y to continue) ==> ";
		cin >> loop;
		
		cout << endl;
	}
}

void makePascalTriangle(vector<vector<int>>& triangle, const int& size, int line)
{
	if (line == 0)
	{
		return;
	}
	makePascalTriangle(triangle, size, line-1);
	for (int idx = 0; idx <= size-1; idx++)
	{
		triangle[line][idx] = triangle[line-1][idx] + triangle[line-1][idx+1];
	}
}

int findWidth(const vector<vector<int>>& triangle, const int& size)
{
	return(((log10(triangle[size][size/2]))+1)/2+1);
}

void printPascalTriangle(vector<vector<int>>& triangle, const int& size)
{
	makePascalTriangle(triangle, size, size);
	int width = findWidth(triangle, size);
	for (int i = 0; i <= size; i++)
	{
		for (int j = 0; j <= size; j++)
		{
			if (triangle[i][j] == 0)
			{
				cout.width(width);
				cout << ' ';
			}
			else
			{
				cout << setw(width*2) << left << triangle[i][j];
			} 
		}
		cout << endl;
	}
	cout << endl;
}




/** A Sample Output
=====================================================================
Harper CSC121-002 by Mr. Jin Guo: Optional #9, Spring 2023
Student: Zach Perkins

This program will print out a Pascal Triangle with a fixed size.
The size is input from keyboard and it's suggested that the size
be <= 20 or the result will be too large to be displayed on screen.
=====================================================================

Please input N for (a+b)^N (N >= 0, e.g., 6) ==> 0
1

-------------------------------------------------------
Do you want to do this again? (y/Y to continue) ==> y

Please input N for (a+b)^N (N >= 0, e.g., 6) ==> 1
 1
1 1

-------------------------------------------------------
Do you want to do this again? (y/Y to continue) ==> y

Please input N for (a+b)^N (N >= 0, e.g., 6) ==> 2
  1
 1 1
1 2 1

-------------------------------------------------------
Do you want to do this again? (y/Y to continue) ==> y

Please input N for (a+b)^N (N >= 0, e.g., 6) ==> 6
            1
          1   1
        1   2   1
      1   3   3   1
    1   4   6   4   1
  1   5   10  10  5   1
1   6   15  20  15  6   1

-------------------------------------------------------
Do you want to do this again? (y/Y to continue) ==> y

Please input N for (a+b)^N (N >= 0, e.g., 6) ==> 9
                  1
                1   1
              1   2   1
            1   3   3   1
          1   4   6   4   1
        1   5   10  10  5   1
      1   6   15  20  15  6   1
    1   7   21  35  35  21  7   1
  1   8   28  56  70  56  28  8   1
1   9   36  84  126 126 84  36  9   1

-------------------------------------------------------
Do you want to do this again? (y/Y to continue) ==> n

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

