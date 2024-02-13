/*
======================================================================================
Course: Harper CSC121-002 by Mr. Jin Guo, Spring 2023
Student Name: Zach Perkins

Program Name: Play with C++ <string>
Program Description:
	This program is for you to practice some of the <string> member functions and 
	its overloaded operators such as .length(), .size(). .find(), .substr(), 
	.replace(), .erase() and .append(), "[]", "+", "==", etc. You can go to the 
	website www.cplusplus.com to find more about <string> libary. 

Instructions:
	1. Thoroughly understand and run the given program before you do any change.
	2. Run h7_JG.out and refer to the sample output at the end of this file. Your 
		finished program should perform the same as h7_JG.out does.	
	3. See the required tasks within the program. Insert your code below wherever 
		is marked "Your code below...". Don't remove any existing code. Re-use
		the declared variables whenever possible.
	4. Please follow the given code style including indent format.
	5. Submit only your .cpp file with your change. Name your file properly
		as usual.

Notes: 
	1. size_t is type "unsigned int". It's usually used for size and position.
	2. strlen() from <cstring> may be used to find the size of a C-string, e.g,
		strlen("Good morning") will return 12.

References: 
	Class Notes -> CSC121 ClassNote3: Function Prototype
	s06c_Cpp_string_member_functions.cpp

Created: 9/8/2007 by Jin Guo
Updated: 10/28/2014 by Jin Guo. Customized for Harper.
Updated: 3/11/2021. Significant changes for this new semester.
Updated: 2/21/2023. Adapted for this semester.
======================================================================================
*/
#include <iostream>
#include <string>
#include <sstream>	// for ostringstream
#include <cstring>	// for strlen()
#include <cstdlib>	// for size_t

using namespace std;

// This function prints out a string with double quotes.
inline string inDoubleQuote(const string& str) 
{ return "\"" + str + "\""; }

// This function prints out a string's contents, length, capacity, etc.
string strDetail(const string& str);

int main()
{
	cout << "=====================================================================\n";
	cout << "Harper CSC121-002 by Mr. Jin Guo: Assignment #7, Spring 2023 \n";
	cout << "Student: Zach Perkins\n\n";
	cout << "This program is for you to exercise some of C++ <string> operations.\n";
	cout << "=====================================================================\n\n";

	// Construct some strings
	string str1("Water is so soft, ");		// declared str1 with some contents.
	string str2 = "But it is very strong."; // declared str2 with initialization.
	string str3;							// declared str3 as an empty string.

	cout << ">>>>> At the beginning ......\n";
	cout << "str1: " << strDetail(str1) << endl;
	cout << "str2: " << strDetail(str2) << endl;
	cout << "str3: " << strDetail(str3) << endl;

	cout << ">>> After str1 = \"On the earth, \" + str1,\n";
	str1 = "On the earth, " + str1;
	cout << "str1: " << inDoubleQuote(str1) << endl;
	
	size_t pos; // to save the position info for a string.

	// Use str1[i] or str1.at(i) to change a char in str1;
	cout << "\n>>> Find \"Water\" and replace \"w\" with \"W\" ...\n";
	pos = str1.find("Water");
	str1[pos] = 'w';
	cout << "str1: " << inDoubleQuote(str1) << endl;

	cout << "\n>>> Find and erase \"so\" ...\n";
	pos = str1.find("so");
	str1.erase(pos, 3);
	cout << "str1: " << inDoubleQuote(str1) << "\n";

	cout << "\n>>> After str3 = str1 + str2; ...\n";
	str3 = str1 + str2;
	cout << "str3: " << inDoubleQuote(str3) << endl;

	cout << "\n>>> Find \"But\" and replace it with \"yet\" ...\n";
	pos = str3.find("But");
	str3.replace(pos, 3, "yet");
	cout << "str3: " << inDoubleQuote(str3) << endl;

	cout << "\n>>> Find and erase \"very\" ...\n";
	pos = str3.find("very");
	str3.erase(pos, strlen("very "));
	cout << "str3: " << inDoubleQuote(str3) << "\n\n";

	/*
	=================================================================================	
	<<<<<< Your code below ... >>>>>

	Please finish the following tasks. Please run h7_JG.out and follow the given 
	output and style including blank lines. Variable pos should be reused.

	Construct str4 with "I used to love a country life in Montana!", then use only
	.find(), .replace(), .erase(), .substr() and "+" to change str4 so that 
	str4 contains "But now I love an urban life in Chicago!". Don't skip any steps 
	in the output. Follow all the small steps below to change str4:
		1) Construct str4.
		2) Erase "used to ".
		3) Add "But now " to front of str4.
		4) Replace "a country" with "an urban".
		5) Replace "Montana" with "Chicago".
	=================================================================================	
	*/
	cout << "===========================================\n";
	cout << ">>>>> My code below ... >>>>>\n";
	cout << "===========================================\n";

	string str4 = "I used to love a country life in Montana!";
	
	cout << "\n>>> At the beginning, construct str4 ...\n";
	cout << "str4: " << inDoubleQuote(str4) << endl;

	cout << "\n>>> Find and erase \"used to \" ...\n";
	pos = str4.find("used to ");
	str4.erase(pos, strlen("used to "));
	cout << "str4: " << inDoubleQuote(str4) << endl;
	
	cout << "\n>>> After str4 = \"But now \" + str4 ...\n";
	str4 = "But now " + str4;
	cout << "str4: " << inDoubleQuote(str4) << endl;
	
	cout << "\n>>> Find and replace \"a country\" with \"an urban\" ...\n";
	pos = str4.find("a country");
	str4.replace(pos, strlen("a country"), "an urban");
	cout << "str4: " << inDoubleQuote(str4) << endl;
	
	cout << "\n>>> Find and replace \"Montana\" with \"Chicago\" ...\n";
	pos = str4.find("Montana");
	str4.replace(pos, strlen("Montana"), "Chicago");
	cout << "str4: " << inDoubleQuote(str4) << endl;

	cout << endl;
}

//=======================================================
string strDetail(const string& str)
{
	ostringstream strInfo;

	strInfo << inDoubleQuote(str) << "\n"
		<< "length: " << str.length()
		<< " | empty: " << boolalpha << str.empty()
		<< " | capacity: " << str.capacity()
		<< " | max size: " << str.max_size() << "\n";

	return strInfo.str();
}

/* A Sample Output
=====================================================================
Harper CSC121-002 by Mr. Jin Guo: Assignment #7, Spring 2023
Student: Zach Perkins

This program is for you to exercise some of C++ <string> operations.
=====================================================================

>>>>> At the beginning ......
str1: "Water is so soft, "
length: 18 | empty: false | capacity: 31 | max size: 4294967294

str2: "But it is very strong."
length: 22 | empty: false | capacity: 31 | max size: 4294967294

str3: ""
length: 0 | empty: true | capacity: 15 | max size: 4294967294

>>> After str1 = "On the earth, " + str1,
str1: "On the earth, Water is so soft, "

>>> Find "Water" and replace "w" with "W" ...
str1: "On the earth, water is so soft, "

>>> Find and erase "so" ...
str1: "On the earth, water is soft, "

>>> After str3 = str1 + str2; ...
str3: "On the earth, water is soft, But it is very strong."

>>> Find "But" and replace it with "yet" ...
str3: "On the earth, water is soft, yet it is very strong."

>>> Find and erase "very" ...
str3: "On the earth, water is soft, yet it is strong."

===========================================
>>>>> My code below ... >>>>>
===========================================

>>> At the beginning, construct str4 ...
str4: "I used to love a country life in Montana!"

>>> Find and erase "used to " ...
str4: "I love a country life in Montana!"

>>> After str4 = "But now " + str4 ...
str4: "But now I love a country life in Montana!"

>>> Find and replace "a country" with "an urban" ...
str4: "But now I love an urban life in Montana!"

>>> Find and replace "Montana" with "Chicago" ...
str4: "But now I love an urban life in Chicago!"

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

