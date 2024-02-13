/*
====================================================================================
Course: Harper CSC121-002 by Mr. Jin Guo, Spring 2023
Student Name: Zach Perkins

Program Name: Find the Bad Coin
Program Description:
	There are 12 coins and one is a counterfeit. It's either lighter or heavier.
	Use a balance scale to weigh no more than three times to find the counterfeit 
	and also determine it's either lighter or heavier. 

	C++ advanced constructs such as loop-control and function were avoided in the 
	given code. Selection statements are what you should focus on.

Instructions:
	1. First, understand, compile and run the given program without any change.
	2. Run op1_JG.out a couple of times. When you're done, your program should
		perform the same as this one does. 
	3. Add your code to wherever is marked "Your code below...". Please follow
		the given code style, such as indent format.
	4. Please do not remove any existing statements. The given variables should
		be re-used whenever possible.
	5. Submit only the .cpp file with your work. The given file name is
		op1_findBadCoin.cpp. When you are done, you should rename the file
		with your login, e.g., op1_findBadCoin_j_smith.cpp.

Notes: 
	There are more than one ways to solve this 12-coin puzzle. On Blackboard, 
	two videos which show the same algorithm are listed. Search for yourself on 
	Internet or on YouTube with "twelve coins puzzle", you may find quite some others.
	You may also challenge yourself to find one of your own. 

	The following link shows a different algorithm than the two videos: 
	http://www.numericana.com/answer/weighing.htm

	The algorithm I used in this program is the one the two videos on Bb 
	shown as follows:
	1. Name the coins a1,a2,...,a12. 
	2. Specify a bad one which is either lighter or heavier. The user can let 
		computer to make the decision or he can make his own choice.
	3. First, weigh (a1,a2,a3,a4)(left) vs. (a5,a6,a7,a8)(right). 
		If they are balanced, we know that the bad one is in (a9.a10,a11,a12). 
		Otherwise, we know that the bad one is (a1-a8). Use three good ones
		to replace (a6,a7,a8) on right and use (a6,a7,a8) to replace 
		(a2,a3,a4).
	4. You are expected to figure out the rest of the algorithm by reading the above
		website.

Created: 2/1/2015 by Jin Guo.
Updated: 8/29/2019 by Jin Guo. Changed for new semester. Show bad coin's number 
			and being lighter or heavier if it's picked up by computer.
Updated: 9/7/2021 by Jin Guo. Adapted for this semester.
====================================================================================
*/
#include <iostream>
#include <cstdlib>	// for srand() and rand()
#include <time.h>	// for time()

using namespace std;

int main()
{
	// Print header.
	cout << "==================================================================\n";
	cout << "Harper CSC121-002 by Mr. Jin Guo: Optional #1, Spring 2023 \n";
	cout << "Student: Zach Perkins\n\n";
	cout << "There are 12 coins and one is bad. It's either lighter or heavier.\n"; 
	cout << "First pick up the bad one and specify it's lighter or heavier.\n";
	cout << "The program will find the bad one with each step shown.\n";
	cout << "==================================================================\n\n";

	int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12;
	int badNum;
	int badWeight; 
	char ch;

	// Assume good coins have weight of 10.
	a1 = a2 = a3 = a4 = a5 = a6 = a7 = a8 = a9 = a10 = a11 = a12 = 10;

	cout << "Do you want to choose which one is bad by yourself? (y/n) ==> ";
	cin >> ch;

	if (ch == 'y' || ch == 'Y')
	{
		cout << "\nPlease enter the bad coin number (1-12) ==> ";
		cin >> badNum;
		cout << "\nPlease specify the bad coin to be lighter or heavier (l or h) ==> ";
		cin >> ch;
		if (ch == 'l') // bad one is lighter
			badWeight = 9;
		else
			badWeight = 11;
	}
	else
	{
		cout << "OK, computer will randomly choose a lighter or heavier bad coin ...\n";

		// Seed the rand() by using the time function.
		int t = (int)(time(0));	// cast to int to avoid a warning
		srand(t);		// seed random number generator

		badNum = 1 + rand() % 12;		// randomly choose a bad coin.
		badWeight = (rand() % 2) ? 9 : 11;	// randomly choose lighter or heavier.
		cout << "::: The bad coin is " << badNum << " and it's " 
			<< ((badWeight == 9) ? "lighter." : "heavier.") << " :::\n\n";
	}

	switch (badNum)
	{
		case 1: a1 = badWeight; break;
		case 2: a2 = badWeight; break;
		case 3: a3 = badWeight; break;
		case 4: a4 = badWeight; break;
		case 5: a5 = badWeight; break;
		case 6: a6 = badWeight; break;
		case 7: a7 = badWeight; break;
		case 8: a8 = badWeight; break;
		case 9: a9 = badWeight; break;
		case 10: a10 = badWeight; break;
		case 11: a11 = badWeight; break;
		case 12: a12 = badWeight; break;

		default: 
			cout << ">>> Something wrong! Debug your program!\n\n";
			return 1;
	}

	cout << ">>> Let's find the secret bad coin ...\n\n";

	int sum1_4 = a1 + a2 + a3 + a4;
	int sum5_8 = a5 + a6 + a7 + a8;

	if (sum1_4 == sum5_8) // the bad one is (a9-a12)
	{
		cout << "Weigh-1: (a1,a2,a3,a4) == (a5,a6,a7,a8), \n";
		cout << ">>> Found the bad one is in (a9-a12) ...\n";
		
		if (a1 + a2 + a3 == a9 + a10 + a11) // a12 is bad
		{
			cout << "\nWeigh-2: (a1,a2,a3) == (a9,a10,a11),\n";
			cout << ">>> Found a12 is the bad coin ...\n";

			cout << "\nWeigh-3: a1(good) vs. a12\n";
			if (a1 > a12 )
				cout << ">>> Found a12 is the bad one and it's lighter!\n";
			else
				cout << ">>> Found that a12 is the bad one and it's heavier!\n";
		}
		else if (a1 + a2 + a3 > a9 + a10 + a11)
		{
			cout << "\nWeigh-2: (a1,a2,a3) > (a9,a10,a11),\n";
			cout << ">>> Found that the bad one is in (a9,a10,a11) and it's lighter ...\n";

			cout << "\nWeigh-3: a9 vs. a10\n";
			if (a9 == a10)
				cout << ">>> Found that a11 is the bad one and it's lighter!\n";
			else if (a9 < a10)
				cout << ">>> Found that a9 is the bad one and it's lighter!\n";
			else
				cout << ">>> Found that a10 is the bad one and it's lighter!\n";
		}
		else // (a1 + a2 + a3 < a9 + a10 + a11)
		{
			cout << "\nWeigh-2: (a1,a2,a3) < (a9,a10,a11),\n";
			cout << ">>> Found that the bad one is in (a9,a10,a11) and it's heavier ...\n";

			cout << "\nWeigh-3: a9 vs. a10\n";
			if (a9 == a10)
				cout << ">>> Found that a11 is the bad one and it's heavier!\n";
			else if (a9 < a10)
				cout << ">>> Found that a10 is the bad one and it's heavier!\n";
			else
				cout << ">>> Found that a9 is the bad one and it's heavier!\n";
		}
	}
	else if (sum1_4 > sum5_8)
	{
		cout << "Weigh-1: (a1,a2,a3,a4) > (a5,a6,a7,a8), \n";
		cout << ">>> Found the bad one is in (a1-a8) ...\n";

		if ((a1 + a6 + a7 + a8) == (a5 + a9 + a10 + a11))
		{
			cout << "\nWeigh-2: (a1,a6,a7,a8) == (a5,a9,a10,a11),\n";
			cout << ">>> Found that the bad one is in (a2,a3,a4) and is heavier ...\n";

			cout << "\nWeigh-3: a2 vs. a3\n";
			if (a2 == a3)
				cout << ">>> Found that a4 is the bad one and it's heavier!\n";
			else if (a2 > a3)
				cout << ">>> Found that a2 is the bad one and it's heavier!\n";
			else // a2 < a3
				cout << ">>> Found that a3 is the bad one and it's heavier!\n";
		}
		else if ((a1 + a6 + a7 + a8) > (a5 + a9 + a10 + a11))
		{
			cout << "\nWeigh-2: (a1,a6,a7,a8) > (a5,a9,a10,a11)...\n";
			cout << ">>> Found that either a1 is heavier or a5 is lighter ...\n";

			cout << "\nWeigh-3: a1 vs. a12(good)\n";
			if (a1 > a12)
				cout << ">>> Found that a1 is the bad one and it's heavier!\n";
			else
				cout << ">>> Found that a5 is the bad one and it's lighter!\n";
		}
		else // (a1 + a6 + a7 + a8) < (a5 + a9 + a10 + a11)
		{
			cout << "\nWeigh-2: (a1,a6,a7,a8) < (a5,a9,a10,a11)...\n";
			cout << ">>> Found that the bad one is in (a6,a7,a8) and is lighter ...\n";

			cout << "\nWeigh-3: a6 vs. a7\n";
			if (a6 == a7)
				cout << ">>> Found that a8 is the bad one and it's lighter!\n";
			else if (a6 < a7)
				cout << ">>> Found that a6 is the bad one and it's lighter!\n";
			else
				cout << ">>> Found that a7 is the bad one and it's lighter!\n";
		}
	}
	else // (sum1_4 < sum5_8)
	{
		// When you are done with your code, comment out the statement below.
		// cout << "!!! This is the case to be implemented by student ...\n";

		/*
		================================
		 <<<<<< Your code below... >>>>>
		================================
		*/
		cout << "Weigh-1: (a1,a2,a3,a4) < (a5,a6,a7,a8), \n";
		cout << ">>> Found the bad one is in (a1-a8) ...\n";

		if ((a1 + a6 + a7 + a8) == (a5 + a9 + a10 + a11))
		{
			cout << "\nWeigh-2: (a1,a6,a7,a8) == (a5,a9,a10,a11),\n";
			cout << ">>> Found that the bad one is in (a2,a3,a4) and is lighter ...\n";

			cout << "\nWeigh-3: a2 vs. a3\n";
			if (a2 == a3)
				cout << ">>> Found that a4 is the bad one and it's lighter!\n";
			else if (a2 > a3)
				cout << ">>> Found that a3 is the bad one and it's lighter!\n";
			else // a2 < a3
				cout << ">>> Found that a2 is the bad one and it's lighter!\n";
		}
		else if ((a1 + a6 + a7 + a8) < (a5 + a9 + a10 + a11))
		{
			cout << "\nWeigh-2: (a1,a6,a7,a8) < (a5,a9,a10,a11)...\n";
			cout << ">>> Found that either a1 is lighter or a5 is heavier ...\n";

			cout << "\nWeigh-3: a1 vs. a12(good)\n";
			if (a1 < a12)
				cout << ">>> Found that a1 is the bad one and it's lighter!\n";
			else
				cout << ">>> Found that a5 is the bad one and it's heavier!\n";
		}
		else // (a1 + a6 + a7 + a8) > (a5 + a9 + a10 + a11)
		{
			cout << "\nWeigh-2: (a1,a6,a7,a8) > (a5,a9,a10,a11)...\n";
			cout << ">>> Found that the bad one is in (a6,a7,a8) and is heavier ...\n";

			cout << "\nWeigh-3: a6 vs. a7\n";
			if (a6 == a7)
				cout << ">>> Found that a8 is the bad one and it's heavier!\n";
			else if (a6 < a7)
				cout << ">>> Found that a7 is the bad one and it's heavier!\n";
			else
				cout << ">>> Found that a6 is the bad one and it's heavier!\n";
		}
	}
		
	// Print out the each coin with its weight to verify the answer.
	cout << "\n>>> To verify the answer, here is the list of coins:\n";
	cout << "a1 = " << a1 << ", \t";
	cout << "a2 = " << a2 << ", \t";
	cout << "a3 = " << a3 << ", \t";
	cout << "a4 = " << a4 << ", \t\n";
	cout << "a5 = " << a5 << ", \t";
	cout << "a6 = " << a6 << ", \t";
	cout << "a7 = " << a7 << ", \t";
	cout << "a8 = " << a8 << ", \t\n";
	cout << "a9 = " << a9 << ", \t";
	cout << "a10 = " << a10 << ", \t";
	cout << "a11 = " << a11 << ", \t";
	cout << "a12 = " << a12 << " \t\n";

	cout << endl;
}

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

