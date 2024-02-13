/*
====================================================================================
ourse: Harper CSC121-002 by Mr. Jin Guo, Spring 2023
Student Name: Zach Perkins

Program Name: Hit Ratios of Two Dice
Program Description:
	This program will find some hit ratios of two dice. Each die has 6 sides
	with each marked as 1,2,3,4,5 and 6, respectively. When two dice are thrown
	together, add the dice numbers and find the hit ratios for 5, 6 and 8.

Instructions:
	1. Run op4_JG.out a couple of times. When you are done, your program should 
		perform the same as this one does . 
	2. Make the number of throws (e.g., 1'000'000) for each game as an int constant 
		variable and the number of games (e.g., 10) as another int constant variable.
	3. Please follow the given code style and format. 
	4. Submit only your .cpp file. Name your file properly as usual.

Notes:
	<ctime>:	for time(), which is used to seed rand().
	<iomanip>:	for setprecision(), setw()
	<cstdlib>:	for  rand() which generates a random number and srand() which 
				seeds rand() so every time you run your program a different series 
				of random numbers will be generated. 

	In general, integer operations are faster and use less memory than double's. 
	The rule is, "Whenever an integral type can be used, don't use a floating type."
	For example, age, counter and position should be of "unsigned int" (size_t) 
	not double. To preserve the decimal part when division is applied to two 
	integers, you need to cast one of them to be double. And of course, the variable 
	to hold the result should be type of double.

References:
	The referenc book (C++ How to Program) programs: 
	fig06_07.cpp
	fig06_08.cpp
	fig06_09.cpp

Created: 6/17/2016 by Jin Guo.
Updated: 2/17/2023 by Jin Guo. Adapted for this semester.
====================================================================================
*/
#include <iostream>
#include <ctime>	// for time() as seed of rand()
#include <iomanip>	// for fixed, setprecision()
#include <cstdlib>	// for srand(), rand()

using namespace std;

int main()
{
	cout << "==================================================================\n";
	cout << "Harper CSC121-002 by Mr. Jin Guo: Optional #4, Spring 2023 \n";
	cout << "Student: Zach Perkins\n\n";
	cout << "This program will find the hit ratios of 5, 6 and 8 for two dices.\n";
	cout << "==================================================================\n\n";

	srand((int)time(0));
	
	const int throws = 1'000'000;
	const int games = 10;
	
	cout << "For each play, two dice are thrown " << throws << " times\n";
	cout << "Totally, " << games << " games are played.\n\n";
	cout << "Game    hit_5   hit_6   hit_8\n";
	cout << "~~~~    ~~~~~   ~~~~~   ~~~~~\n";
	
	for (int game = 1; game <= games; game++)
	{
		int roll_5, roll_6, roll_8, roll;
		roll_5 = roll_6 = roll_8 = 0;
		
		for (roll = 0; roll < throws; roll++)
		{
			int d1 = rand() % 6 + 1;
			int d2 = rand() % 6 + 1; 
			
			switch( d1 + d2 ) 
			{
				case 5:
					roll_5++;
					break;
				case 6:
					roll_6++;
					break;
				case 8:
					roll_8++;
					break;
			}
		}
		
		double hit_5, hit_6, hit_8;
		hit_5 = 1.0 * roll_5 / roll;
		hit_6 = 1.0 * roll_6 / roll;
		hit_8 = 1.0 * roll_8 / roll;
		
		cout << right << setw(4) << game << "    ";
		cout << fixed;
		cout << setprecision(3) << hit_5 << "   ";
		cout << setprecision(3) << hit_6 << "   ";
		cout << setprecision(3) << hit_8 << endl;
	}
	
	cout << endl;
}

/* A Sample Output
==================================================================
Harper CSC121-002 by Mr. Jin Guo: Optional #4, Spring 2023
Student: Zach Perkins

This program will find the hit ratios of 5, 6 and 8 for two dice.
==================================================================

For each play, two dice are thrown 1000000 times
Totally, 10 games are played.

Game    hit_5   hit_6   hit_8
~~~~    ~~~~~   ~~~~~   ~~~~~
   1    0.111   0.139   0.139
   2    0.111   0.139   0.139
   3    0.111   0.139   0.139
   4    0.111   0.139   0.140
   5    0.111   0.139   0.139
   6    0.111   0.139   0.139
   7    0.111   0.139   0.139
   8    0.111   0.139   0.139
   9    0.111   0.139   0.138
  10    0.111   0.138   0.139

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

