/*  
==================================================================================
Course: Harper CSC121-002 by Mr. Jin Guo, Spring 2023
Student Name: Zach Perkins

Program Name: Arithmetic for Kids
Program Description: 	
	This is a program for kids to practice basic arithmetic. User can choose 
	addition, subtraction, multiplication and division from the menu. 
	Each problem is given three chances for the right answer. 

Instructions: 
	1. First run the executable op8_JG.out a couple of times to see how it works. 
		Your finished program should perform the same as this one does.Then read 
		and try to understand the given program. 
	2. Only division was implemented in the given code. You are asked to implement 
		addition, subtraction and multiplication. Here are the number ranges for 
		each operation:
		1) a + b: a and b are in [1, 99].
		2) a - b: a and b are in [1, 99] and b <= a.
		3) a * b: a is in [2, 30] and b is in [2, 10].
		4) a / b: a is in [20, 200], b is in [2, 20] and b should divide a.
	3. Insert your code wherever is marked "Your code below...".
	4. Submit only your .cpp file and name it properly as usual.

Created: 6/20/2013 by Jin Guo
Updated: 7/8/2021 by Jin Guo. Adapted for this semester with some improvements. 
Updated: 11/4/2022 by Jin Guo. Some improvements. getRandNumInRange() added.
		Adapted for this semester. Minor improvements.
Updated: 3/27/2023. Adapted for this semester.
===================================================================================
*/  
#include <iostream>
#include <string>
#include <sstream>		// for istringstream 
#include <cstdlib>		// for rand()
#include <ctime>		// for time() as a seed for srand()
#include <algorithm>	// for swap()
#include <climits>		// for INT_MAX

using namespace std;

static const int numOfTries = 3; // set number of tries as a constant.

// The following are auxiliary functions
string& strToLower(string& str);			// turn the string into lower case.
bool strIsInt(int& k, const string& str);	// make sure a string is an integer.
bool isValidChoice(char ch);				// return true if a selection is valid. 
int getRandNumInRange(int low, int high);	// return an int in [low, high].

// The following are for main menu control.
void showMainMenu();		// show the main menu.
void chooseOneOp(char ch);	// choose one of the arithmetic.

// The following functions are for arithmetic operations.
void divideTwoIntegers();
void divideTwoIntegersLoop();  

/*
=======================================================================
You need to add function prototypes below for addition,
subtraction and multiplication.
<<<<<< Your code below... >>>>>
========================================================================
*/
void addTwoIntegers();
void addTwoIntegersLoop();
void subtractTwoIntegers();
void subtractTwoIntegersLoop();
void multiplyTwoIntegers();
void multiplyTwoIntegersLoop();


int main() 
{
	cout << "=============================================================\n";
	cout << "Harper CSC121-002 by Mr. Jin Guo: Optional #8, Spring 2023\n";
	cout << "Student: Zach Perkins\n\n";
	cout << "This program is for kids to exercise arithmetic.\n";
	cout << "=============================================================\n\n";

	srand(static_cast<size_t> (time(0)));	// seed random number generator

	while (true)
	{
		showMainMenu();

		char choice; 
		do
		{
			cout << "Please choose one of the above ==> ";
			cin >> ws >> choice;	
			cin.ignore(INT_MAX, '\n'); // discard extra chars from previous input.

			if (isValidChoice(choice))
				break;
			
			cout << "Wrong choice! ";
		} while (true);

		if (tolower(choice) == 'q')
		{
			cout << "\n=== Thanks for using! See you again! ===\n";
			break;
		}

		chooseOneOp(choice);		
	} 
 
	cout << endl;
}

// The following are function definitions.
//==================================================================
inline
int getRandNumInRange(int low, int high)
{
	return low + rand() % (high - low + 1);
}

string& strToLower(string& str)
{
	for (size_t i = 0; i < str.size(); i++)
		str[i] = tolower(str[i]);

	return str; // address of str is copied out.
}

bool strIsInt(int& k, const string& str)
{
	// "input" is an object of istringstream which takes input from str.
	istringstream input(str);  

	input >> k;
	return (input.fail()) ? false : true;
	//return ((input >> k) ? true : false); // this also worked!
}

bool isValidChoice(char ch) 
{  
	if (ch < '1' || (ch > '4' && tolower(ch) != 'q')) 
		return false; 
	else 
		return true; 
} 

void showMainMenu() 
{ 
	cout << "==============================================\n";
	cout << "| This is an elementary arithmetic practice. |\n";
	cout << "| You may choose one of the operations below.|\n";
	cout << "|--------------------------------------------|\n";
	cout << "|  1: Addition.                              |\n";
	cout << "|  2: Subtraction.                           |\n";								
	cout << "|  3: Multiplication.                        |\n";  
	cout << "|  4: Division.                              |\n";
	cout << "|  q/Q: to quit.                             |\n";  
	cout << "==============================================\n";
} 

void chooseOneOp(char choice) // Choose one of the arithmetic.
{ 
	switch(choice) 
	{  
	case '1':  
		cout << "\nYou have chosen to do Addition...\n"; 
		// Your code below...
		addTwoIntegersLoop();
		break;  
	case '2':  
		cout << "\nYou have chosen to do Subtraction...\n"; 
		// Your code below...
		subtractTwoIntegersLoop();
		break;  
	case '3':  
		cout << "\nYou have chosen to do Multiplication...\n";  
		// Your code below...
		multiplyTwoIntegersLoop();
		break;  
	case '4':  
		cout << "\nYou have chosen to do Division...\n";  
		divideTwoIntegersLoop(); 
		break; 
	default:
		cout << "\n>>> Should never come here, a bug in the program!!!\n\n";
		exit(1);
	}  
	
	cout << endl;  
}  

void divideTwoIntegersLoop()
{
	string choice; // for control of repeat

	do 
	{
		divideTwoIntegers();

		cout << "\nDo you want to do Division again?\n";
		cout << "(yes/YES to continue) ==> ";
		cin >> ws; // skip leading spaces.
		getline(cin, choice); // get the whole line as input.
	} while (strToLower(choice).substr(0, 3) == "yes" || choice[0] == 'y');

	cout << "OK--Back to main menu ...\n";
}

void divideTwoIntegers()
{
	const int low1 = 20, high1 = 200, low2 = 2, high2 = 20;
	int a; // dividend
	int b; // divisor
	int c; // quotient

	do 
	{
		a = getRandNumInRange(low1, high1);	// generate a number in [20, 200]
		b = getRandNumInRange(low2, high2); // generate a number in [2, 20].
	} while (a % b); // b should divide a. 
	
	c = a / b; // b divides a.

	for (int i = 1; i <= numOfTries; i++)
	{
		int answer;
		string str; // for answer input from keyboard

		do
		{
			cout << "\nWhat is " << a << " / " << b << " ? ==> ";
			getline(cin, str);
			if (strIsInt(answer, str))
				break;
			cout << "Not an integer! please input an integer!\n";
		} while (true);

		if (answer == c) // correct answer is reached.		
		{
			cout << "You got it!\n";
			break;
		}

		if (i == numOfTries) // number of tries has been reached.
		{
			cout << "Still not correct. You have tried " << numOfTries << " times.\n";
			cout << "The correct answer is: " << c << endl;
			break; // out of for loop.
		}

		cout << "That's not correct. Try again,\n";
	}
}

/*
=======================================================================
You need to add lines in chooseOneOp() when are done with addition,
subtraction and multiplication
<<<<<< Your code below... >>>>>
========================================================================
*/

void addTwoIntegersLoop()
{
	string choice; // for control of repeat

	do 
	{
		addTwoIntegers();

		cout << "\nDo you want to do Addition again?\n";
		cout << "(yes/YES to continue) ==> ";
		cin >> ws; // skip leading spaces.
		getline(cin, choice); // get the whole line as input.
	} while (strToLower(choice).substr(0, 3) == "yes" || choice[0] == 'y');

	cout << "OK--Back to main menu ...\n";
}

void addTwoIntegers()
{
	const int low1 = 1, high1 = 99, low2 = 1, high2 = 99;
	int a; 
	int b; 
	int c; 

	a = getRandNumInRange(low1, high1);	// generate a number in [1, 99]
	b = getRandNumInRange(low2, high2); // generate a number in [1, 99].
	
	c = a + b;

	for (int i = 1; i <= numOfTries; i++)
	{
		int answer;
		string str; // for answer input from keyboard

		do
		{
			cout << "\nWhat is " << a << " + " << b << " ? ==> ";
			getline(cin, str);
			if (strIsInt(answer, str))
				break;
			cout << "Not an integer! please input an integer!\n";
		} while (true);

		if (answer == c) // correct answer is reached.		
		{
			cout << "You got it!\n";
			break;
		}

		if (i == numOfTries) // number of tries has been reached.
		{
			cout << "Still not correct. You have tried " << numOfTries << " times.\n";
			cout << "The correct answer is: " << c << endl;
			break; // out of for loop.
		}

		cout << "That's not correct. Try again,\n";
	}
}

void subtractTwoIntegersLoop()
{
	string choice; // for control of repeat

	do 
	{
		subtractTwoIntegers();

		cout << "\nDo you want to do Subtraction again?\n";
		cout << "(yes/YES to continue) ==> ";
		cin >> ws; // skip leading spaces.
		getline(cin, choice); // get the whole line as input.
	} while (strToLower(choice).substr(0, 3) == "yes" || choice[0] == 'y');

	cout << "OK--Back to main menu ...\n";
}

void subtractTwoIntegers()
{
	const int low1 = 1, high1 = 99, low2 = 1;
	int a; 
	int b; 
	int c; 

	a = getRandNumInRange(low1, high1);	// generate a number in [1, 99]
	b = getRandNumInRange(low2, a); // generate a number in [1, a]. 
	
	c = a - b; // b divides a.

	for (int i = 1; i <= numOfTries; i++)
	{
		int answer;
		string str; // for answer input from keyboard

		do
		{
			cout << "\nWhat is " << a << " - " << b << " ? ==> ";
			getline(cin, str);
			if (strIsInt(answer, str))
				break;
			cout << "Not an integer! please input an integer!\n";
		} while (true);

		if (answer == c) // correct answer is reached.		
		{
			cout << "You got it!\n";
			break;
		}

		if (i == numOfTries) // number of tries has been reached.
		{
			cout << "Still not correct. You have tried " << numOfTries << " times.\n";
			cout << "The correct answer is: " << c << endl;
			break; // out of for loop.
		}

		cout << "That's not correct. Try again,\n";
	}
}

void multiplyTwoIntegersLoop()
{
	string choice; // for control of repeat

	do 
	{
		multiplyTwoIntegers();

		cout << "\nDo you want to do Multiplication again?\n";
		cout << "(yes/YES to continue) ==> ";
		cin >> ws; // skip leading spaces.
		getline(cin, choice); // get the whole line as input.
	} while (strToLower(choice).substr(0, 3) == "yes" || choice[0] == 'y');

	cout << "OK--Back to main menu ...\n";
}

void multiplyTwoIntegers()
{
	const int low1 = 2, high1 = 30, low2 = 2, high2 = 10;
	int a; 
	int b; 
	int c; 

	a = getRandNumInRange(low1, high1);	// generate a number in [2, 30]
	b = getRandNumInRange(low2, high2); // generate a number in [2, 10].
	
	c = a * b;

	for (int i = 1; i <= numOfTries; i++)
	{
		int answer;
		string str; // for answer input from keyboard

		do
		{
			cout << "\nWhat is " << a << " * " << b << " ? ==> ";
			getline(cin, str);
			if (strIsInt(answer, str))
				break;
			cout << "Not an integer! please input an integer!\n";
		} while (true);

		if (answer == c) // correct answer is reached.		
		{
			cout << "You got it!\n";
			break;
		}

		if (i == numOfTries) // number of tries has been reached.
		{
			cout << "Still not correct. You have tried " << numOfTries << " times.\n";
			cout << "The correct answer is: " << c << endl;
			break; // out of for loop.
		}

		cout << "That's not correct. Try again,\n";
	}
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

