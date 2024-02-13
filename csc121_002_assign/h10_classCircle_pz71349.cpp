/*
=======================================================================================
Course: Harper CSC121-002 by Mr. Jin Guo, Spring 2023
Student Name: Zach Perkins

Program Name: Class Circle
Program Description:
	The class declares and defines class Circle. It has one private data 
	member: radius. Its public member functions include the following:
		Circle() {...} // default constructor
		Circle(double) {...} // constructor with one parameter
		double getRadius() const {...}
		double getArea() const {...}			
		double getCircumference() const {...} // = 2 * PI * radius
		bool isLargerThan(const Circle&) const {...} 
		void setRadius(double) {...}
		void printInfo() const {...} // define this after main.
		
Instructions:
	1. Please run h10_JG.out and your finished program should perform the 
		same as this one does, including output prompts and format. See the 
		sample output at the end of this file.
	2. Imitate the sample program s10a_class_rectangle.cpp to implement the 
		Circle class and write testing code in your main function. 
	3. 	Add your code to wherever is marked with "Your code below ...". 
		Please do not remove any existing code. 
	4. Submit only your .cpp file and name it properly as usual.

Notes: 
	1. For default constructor, use 1.0 as the default value for radius.
	2. PI is defined as a global static const double variable.

Created: 4/3/2012 by Jin Guo
Updated: 7/7/2021 by Jin Guo. Improved function getRadius().
Updated: 3/20/2023 by Jin Guo. Adapted for the new semester.
=======================================================================================
*/
#include <string>
#include <iostream>
#include <iomanip>	// for fixed, setprecision()
#include <climits>	// for INT_MAX

using namespace std;

static const double PI = 3.1415926535;

double getRadius();

class Circle
{
public:
	Circle() : radius(1.0) {}		// default constructor
	Circle(double r) : radius(r) {} // constructor with a parameter

	/*
	===============================================================
	Add other member functions here.
	<<<<< Your code below ... >>>>>
	===============================================================
	*/
	double getRadius() const { return radius; }
	double getArea() const { return (PI * radius * radius); }
	double getCircumference() const { return (2 * PI * radius); }
	bool isLargerThan(const Circle& circle) const { return (getArea() > circle.getArea()); }
	void printInfo(string name = "") const;

	void setRadius(double r) { radius = (r < 0) ? 0.0 : r; }
	
private: 
	double radius; 
};

int main ()
{
	cout << "==================================================================\n";
	cout << "Harper CSC121-002 by Mr. Jin Guo: Assignment #10, Spring 2023 \n";
	cout << "Student: Zach Perkins\n\n";
	cout << "This program will declare, define and test Circle class. \n";
	cout << "==================================================================\n\n";

	cout << "PI = " << fixed << setprecision(8) << PI << "\n\n";

	/*
	===========================================================================
	Imitate the code of s10a_class_rectangle.cpp to test your Circle class.
	<<<<< Your code below ... >>>>>
	===========================================================================
	*/
	
	cout << ">>> Construct circle0 with default constructor ...\n";
	Circle circle0;
	circle0.printInfo();

	cout << "\n>>> Construct circle1 with Circle circle1(10) ...\n";
	Circle circle1(10);
	circle1.printInfo("circle1 --> ");

	cout << "\n>>> Reset radius with circle1.setRadius(5.0) ...\n";
	circle1.setRadius(5.0);
	circle1.printInfo("circle1 --> ");
	
	double r = getRadius();

	cout << "\n>>> Construct circle2 with the value from keyboard ...\n";
	Circle circle2(r);
	circle2.printInfo("circle2 --> ");

	cout << "\n>>> Compare if circle1 and circle2 are the same large ...\n";
	if (circle1.isLargerThan(circle2))
		cout << "circle1 is larger than circle2!\n";
	else
		cout << "circle1 is NOT larger than circle2!\n";

	cout << endl;
}

//==================================================================
double getRadius()
{
	double r;
	do
	{
		cout << "\nInput radius > 0 (e.g., 3.5) ==> ";
		cin >> r;

		if (!cin.fail() && r >= 0.0) // r is a good value.
		{
			cin.ignore(INT_MAX, '\n'); // clear the input buffer.
			return r;
		}

		cin.clear(); // clear tags of cin.
		cin.ignore(INT_MAX, '\n'); // clear the input buffer.
		cout << "Not a valid radius! Please try again ...\n";
	} while (true);
}

/*
===============================================================
Define  Circle::printInfo().
<<<<< Your code below ... >>>>>
===============================================================
*/

void Circle::printInfo(string name) const
{
	cout << name;

	cout << fixed << setprecision(2);
	cout << "|Radius: " << getRadius()
		 << " |Area: " << getArea() 
		 << " |Circumference: " << getCircumference() << "\n";
}

/* A Sample Output
==================================================================
Harper CSC121-002 by Mr. Jin Guo: Assignment #10, Spring 2023
Student: Zach Perkins

This program will declare, define and test Circle class.
==================================================================

PI = 3.14159265

>>> Construct circle0 with default constructor ...
|Radius: 1.00 |Area: 3.14 |Circumference: 6.28

>>> Construct circle1 with Circle circle1(10) ...
circle1 --> |Radius: 10.00 |Area: 314.16 |Circumference: 62.83

>>> Reset radius with circle1.setRadius(5.0) ...
circle1 --> |Radius: 5.00 |Area: 78.54 |Circumference: 31.42

Input radius > 0 (e.g., 3.5) ==> 3.5

>>> Construct circle2 with the value from keyboard ...
circle2 --> |Radius: 3.50 |Area: 38.48 |Circumference: 21.99

>>> Compare if circle1 and circle2 are the same large ...
circle1 is larger than circle2!

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

