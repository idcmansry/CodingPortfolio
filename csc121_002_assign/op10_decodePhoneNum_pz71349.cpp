/*
=======================================================================================
Course: Harper CSC121-002 by Mr. Jin Guo, Spring 2023
Student Name: Zach Perkins

Program Name: Decoding Phone Number
Program Description:
	This program will decode a phone number of some format into a formal format.
	Leading spaces and spaces rounding a number or a delimiter should be ignored. 
	A legal delimiter is one of the chars [+, space, ., -, /, *].

	The following inputs will be valid phone numbers:
	+1(847)642-1245
	+1-847-642-1245
	+86.847-642-1245

	846*642*1245
	847.642.1245
	847-642.1245
	847/642-1245
	(847)642-1245

	"847 - 642 / 1245"	// with spaces around numbers and delimiters
	"  847/642-1245 "	// with leading and ending space

	The following inputs will be invalid phone numbers:
	1(847)642-1245		// country code must starts with +
	(847)642@1245		// @ is an invalid delimiter
	(847)642-1245asdf	// 1245asdf is invalid for line number
	(847)642-1245-234	// too many numbers
	+1(847)642			// too few numbers
	(847-642-1245		// parentheses don't match

	The output will be always formal as: 
	+1(847)642-1245 or (847)642-1245

Instructions:
	1. Run op9_JG.out with all the valid and invalid phone numbers above. When you done, 
		your program should perform as closely as possible as this one does.
	2. Your program should pass all the valid inputs and reject all the invalid
		ones as listed above. Whenever possible, point out what's wrong with 
		an invalid input.
	3. Instructor suggested a frame with some function prototypes. You may create 
		your own but your program should follow the given code style and conventions.
	4. Submit only your .cpp file. Name your file properly as usual.

Notes: 
	1. This program can only compile without being linked. 
	2. Try to pass all the valid inputs first. Then try identify all the
		invalid ones.
	3. Instructor implemented this problem in three different algorithms. Each has 
		its own pros and cons. 

		Algorithm 1: Decode the input and would be able to tell what's wrong in the 
			input, e.g., missing a parenthesis. 
		Algorithm 2: First replace all non-digit chars with space and then check how 
			many numbers in the input. This version is easier to implement but would 
			not be able to tell what's wrong with the input.
		Algorithm 3: Use "regular expression" to precisely detect correct/incorrect 
			input for a phone number. This version is the most challenging. You need
			to study "regular expression" and use 

		The suggested program frame is for Algorithm 1. 

Created: 3/26/2019 by Jin Guo.
Updated: 11/10/2020 by Jin Guo. Fix bugs. Significant improvements.
Updated: 7/28/2021. Adapted for this new semester. Minor improvements.
Updated: 4/11/2023. Adapted for this new semester. Minor improvements.
=======================================================================================
*/
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <iomanip>

using namespace std;

/**
Store the decoded phone number which has four parts: country code, area code, exchange
number and line number. Global variable are accessible by all functions. "static"
means that it is only accessible within this file. All the elements are initialized with 0.
*/ 
static vector<int> decodedPhoneNum(4);

// This is the main control of decoding.
void decodePhoneNumber();

// Print out a decoded phone number in the formal format.
void printPhoneNum(const vector<int>& phoneNum);

/**
The following functions decode country code (starting with +), area code, exchange 
number and line number, respectively and in order. Note that the argument phoneNumInput
is passed in by reference. In extractCountryCode(), after country code is decoded, 
the input is cut off in front and the rest of the input is passed to the next decoding 
function, Similarly with extractArea() and extractExchange().
*/
bool extractCountryCode(string& phoneNumInput);
bool extractArea(string& phoneNumInput);
bool extractExchange(string& phoneNumInput);
bool extractLine(string& phoneNumInput);

int main()
{
	cout << "=============================================================================\n";
	cout << "Harper CSC121-S01 by Mr. Jin Guo: Optional #9, Summer 2021 \n";
	cout << "Student: Zach Perkins\n\n";
	cout << "This program will decode a phone number of some format into a formal format.\n";
	cout << "Leading spaces and spaces rounding a number or a delimiter should be ignored.\n";
	cout << "A legal delimiter is one of the chars [+, space, ., -, /, *].\n";
	cout << "=============================================================================\n\n";

	string choice;
	do
	{
		decodedPhoneNum = vector<int>(4);
		decodePhoneNumber();

		cout << "Try another phone number? (n/N to quit) ==> ";
		cin >> ws;
		getline(cin, choice);
		cout << endl;
	} while (choice[0] != 'N' && choice[0] != 'n');
}

//====================================================================
void decodePhoneNumber()
{
	string phoneNumInput;

	while (true)
	{
		cout << "-----------------------------------------------------------\n";
		cout << "Valid inputs: \n";
		cout << "+1.847/642-1245\n";
		cout << "+1-847-642-1245\n";
		cout << "+85(857)622-1345\n";
		cout << "  +15 - 937 - 232 - 3256\n";
		cout << "  (234)544 - 8655\n";
		cout << "  312 - 348 - 6532\n";
		cout << "-----------------------------------------\n";
		cout << "Invalid inputs: \n";
		cout << "@1.847-642-1245    // with invalid delimiter.\n";
		cout << "+85 (857 622-1345  // parentheses don't match.\n";
		cout << "  +15-337-232      // too few numbers.\n";
		cout << "  (234)-544-8655   // ) should be followed by a number.\n";
		cout << "  (234)544-8655ab  // invalid line number.\n";
		cout << "  312\\348-6532     // delimiter \\ is invalid.\n";
		cout << "-----------------------------------------------------------\n";
		cout << "Please enter a phone number ==> ";

		getline(cin >> ws, phoneNumInput); // skip leading spaces.

		if (!extractCountryCode(phoneNumInput) || !extractArea(phoneNumInput)
			|| !extractExchange(phoneNumInput) || !extractLine(phoneNumInput))
		{
			decodedPhoneNum = vector<int>(4); // reset the vector to be 0.
			cout << "Correct your errors and try again...\n\n";	
			continue;
		}

		break;
	}

	cout << "\n>>> Here is the phone number you typed:\n";
	printPhoneNum(decodedPhoneNum);
	cout << "================================================\n\n";
}

void printPhoneNum(const vector<int>& phoneNum)
{
	if (phoneNum[0] != 0)
	cout << '+' << phoneNum[0];
	cout << '(' << setw(3) << setfill('0') << phoneNum[1];
	cout << ')' << setw(3) << setfill('0') << phoneNum[2];
	cout << '-' << setw(4) << setfill('0') << phoneNum[3];
	cout << endl;
}

bool extractCountryCode(string& phoneNumInput)
{
	if (phoneNumInput[0] != '+')
	{
		return(1);
	}
	
	regex country("\\+\\s?\\d{1,3}\\s?");
	smatch countryCode;
	regex number("\\d{1,3}");
	smatch countryNumber;
	
	if (regex_search(phoneNumInput, countryCode, country))
	{
		regex_search(phoneNumInput, countryNumber, number);
		decodedPhoneNum[0] = stoi(countryNumber[0]);
		phoneNumInput.erase(phoneNumInput.find(countryCode[0]),countryCode[0].length());
		return(1);
	}
	return(0);
}

bool extractArea(string& phoneNumInput)
{
	regex area("(?:\\(\\s?\\d{3}\\s?\\)\\s?)|(?:([\\+\\.\\-\\*/]\\s?)\\d{3}\\s?\\1)|(?:\\d{3}\\s)");
	smatch areaCode;
	regex number("\\d{3}");
	smatch areaNumber;
	
	if (regex_search(phoneNumInput, areaCode, area))
	{
		regex_search(phoneNumInput, areaNumber, number);
		decodedPhoneNum[1] = stoi(areaNumber[0]);
		phoneNumInput.erase(phoneNumInput.find(areaCode[0]),areaCode[0].length());
		return(1);
	}
	return(0);
}

bool extractExchange(string& phoneNumInput)
{
	regex exchange("(?:\\d{3}\\s?[\\+\\.\\-\\*/]\\s?)|(\\d{3}\\s)");
	smatch exchangeCode;
	regex number("\\d{3}");
	smatch exchangeNumber;
	
	if (regex_search(phoneNumInput, exchangeCode, exchange))
	{
		regex_search(phoneNumInput, exchangeNumber, number);
		decodedPhoneNum[2] = stoi(exchangeNumber[0]);
		phoneNumInput.erase(phoneNumInput.find(exchangeCode[0]),exchangeCode[0].length());
		return(1);
	}
	return(0);
}

bool extractLine(string& phoneNumInput)
{
	regex number("\\d{4}");
	smatch lineNumber;
	
	if (regex_search(phoneNumInput, lineNumber, number))
	{
		decodedPhoneNum[3] = stoi(lineNumber[0]);
		phoneNumInput.erase(phoneNumInput.find(lineNumber[0]),lineNumber[0].length());
		return(1);
	}
	return(0);
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

