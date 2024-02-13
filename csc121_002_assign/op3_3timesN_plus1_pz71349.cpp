/*
====================================================================================
Course: Harper CSC121-002 by Mr. Jin Guo, Spring 2023
Student Name: Zach Perkins

Program Name: Testing The Collatz Conjecture
Program Description:
	The Collatz Conjecture is also called 3*N+1 problem. Given any integer N >= 1,  
	if N is even, let N = N /2, otherwise let N = 3*N + 1. Repeat this, N will 
	always reach 4 -> 2 -> 1.

Instructions:
	1. Run op3_JG.out on Unix/Ares. It is the finished executable. Your finished 
		program should perform the same as this one does. See the sample output at
		the end of this file. 
	2. You may use any loop construct, for-loop, while-loop or do-loop to control 
		repetition.
	3. Submit only the .cpp file with your work. Name your file properly as usual.

References:
	s03c_loop_control_by_yes.cpp
	s03e_embedded_loops_demo.cpp
	s04a_double_output_format.cpp

Created: 9/12/2021 by Jin Guo.
Updated: 9/28/2021 by Jin Guo. Code added to fix a bug and make sure the input > 1.
Updated: 2/9/2023 by Jin Guo. Adapted for this semester.
====================================================================================
*/
#include <iostream>  
#include <iomanip>	// for setw()
#include <string>	// for string and getline()
#include <climits>  // for INT_MAX

using namespace std;

int main()
{
	cout << "====================================================================\n";
	cout << "Harper CSC121-002 by Mr. Jin Guo: Optional #3, Spring 2023 \n";
	cout << "Student: Zach Perkins\n\n";
	cout << "This program is to test the 3*N+1 problem. Given any integer N >= 1,\n";
	cout << "if N is even, let N = N / 2, otherwise let N = 3*N + 1.\n";
	cout << "Repeat this, N will always reach 4 -> 2 -> 1.\n";
	cout << "====================================================================\n\n";

	int steps;
	string repeat = "yes";
	long long int init, N;
	
	while (repeat == "yes" || repeat == "YES") 
	{
		steps = 0;
		
		do 
		{
			cout << "Input an integer N > 0 for this problem ==> ";
			cin >> N;
			
			if (N <= 0)
			{
				cout << "Sorry, input must be > 0, please try again ...\n\n";
				N = -1;
			}
			
			init = N;
		} while (N <= 0);
		
		while (N > 1) 
		{
			cout << setw(21) << left << N << "--> ";
			
			N = (N % 2) ? (3 * N + 1) : (N / 2);
			
			cout << N << endl;
			steps++;
		}
		
		cout << ">>> After " << steps << " steps, " << init << " has reached 1!\n";
		cout << "\n==============================================================\n";
		cout << "Do you want to do this again?\n";
		cout << "(yes/YES to continue) ==> ";
		cin >> repeat;
		cout << endl;
	}
	
	cout << endl;
}

/*
====================================================================
Harper CSC121-002 by Mr. Jin Guo: Optional #3, Spring 2023
Student: Zach Perkins

This program is to test the 3*N+1 problem. Given any integer N >= 1,
if N is even, let N = N / 2, otherwise let N = 3*N + 1.
Repeat this, N will always reach 4 -> 2 -> 1.
====================================================================

Input an integer N > 0 for this problem ==> -3
Sorry, input must be > 0, please try again ...

Input an integer N > 0 for this problem ==> 5
5                    --> 16
16                   --> 8
8                    --> 4
4                    --> 2
2                    --> 1
>>> After 5 steps, 5 has reached 1!

==============================================================
Do you want to do this again?
(yes/YES to continue) ==> yes

Input an integer N > 0 for this problem ==> 17
17                   --> 52
52                   --> 26
26                   --> 13
13                   --> 40
40                   --> 20
20                   --> 10
10                   --> 5
5                    --> 16
16                   --> 8
8                    --> 4
4                    --> 2
2                    --> 1
>>> After 12 steps, 17 has reached 1!

==============================================================
Do you want to do this again?
(yes/YES to continue) ==> no


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

