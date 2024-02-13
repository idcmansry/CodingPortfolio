/*
====================================================================================
Course: Harper CSC121-002 by Mr. Jin Guo, Spring 2023
Student Name: Zach Perkins

Program Name:  Calculate Natural Number e
Program Description:
	The following formula can be used to calculate the natural number:
	e = 1/0! + 1/1! + 1/2! + 1/3! + ... + 1/N!

	The larger N is, the more precise e will be. From Internet,
	the value of e = 2.71828182845904523536028747135266249775724709369995

Instructions:
	1. Run op5_JG.out or look at the sample output at the end of this file. 
		When you're done, your program should perform the same as this one does.
	2. Add your code to wherever is marked "Your code below...". Please do not 
		remove any existing code. 
	3. Submit only the .cpp file with your change. Name your file properly as usual.

Notes:
	1. When the result of (n!) becomes large, type int is not big enough. 
		Use an "unsigned long long int" variable to hold n!. Use "long double" 
		for more precision of e.
	2. You may use three-level, two-level or even one-level loop to implement 
		this e-formula.
	3. Understand the meaning of fixed and setprecision().
		fixed: print a double in a flat format not in scientific notation, 
		ending 0's will be padded to decimal part.
		setprecision(n): n digits after decimal point.
	4. You may get different results with the same program running on different
		computers. The more powerful a computer is, the more precision of e
		you will get.
	5. "typedef unsigned long long ullong;" This defines an alias "ullong" 
		for "unsigned long long". The general form is:
		typedef [type_name] [alias_name];
		
		Another new way is to use "usig [alias_name] = [type_name]", e.g., 
		using ullong = unsigned long long;

Created: 9/21/2020 by Jin Guo.
Updated: 10/7/2020 by Jin Guo. Minor changes.
Updated: 2/27/2023 by Jin Guo. Adapted for this semester.
====================================================================================
*/
#include <iostream> 
#include <iomanip>  // for fixed, setprecision().

using namespace std;

using ullong = unsigned long long;	// define a type alias.
using ldouble = long double;		// define a type alias.
/* The following is an old way.
typedef unsigned long long ullong;	// hold value of factorial.
typedef long double ldouble;		// hold value of e.
*/

int main()
{
	cout << "====================================================================\n";
	cout << "Harper CSC121-002 by Mr. Jin Guo: Optional #5, Spring 2023 \n";
	cout << "Student: Zach Perkins\n\n";
	cout << "This program will calculate the natural number e with factorial:\n";
	cout << "e = 1/0! + 1/1! + 1/2! + 1/3! + ... + 1/N!\n\n";
	cout << "The larger N is, the more precise e will be.\n";
	cout << "====================================================================\n\n";

	const size_t upperN = 20; // e = 1/0! + 1/1! + 1/2! +...+ 1/upperN!

	cout << fixed << setprecision(25); // set 25 digits after decimal point.

	cout << "   N" << "     Natural Number e" << "\n";
	cout << "~~~~" << "  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

	/*
	================================
	<<<<<< Your code below... >>>>>
	================================
	*/

	ldouble e = 0;
	ullong fact = 1;
	
	for (int N = 0; N <= upperN; N++)
	{
		if (N > 1)
		{
			fact *= N;
		}
		
		e += 1.0L / fact;
		cout << setw(4) << N << "  " << e << endl;
	}

	cout << endl;
}

/* A Sample Output Running on a Windows PC
====================================================================
Harper CSC121-002 by Mr. Jin Guo: Optional #3, Spring 2023
Student: Zach Perkins

This program will calculate the natural number e with factorial:

e = 1/0! + 1/1! + 1/2! + 1/3! + ... + 1/N!
The larger N is, the more precise e will be.
====================================================================

   N    Natural Number e
~~~~  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   0  1.0000000000000000000000000
   1  2.0000000000000000000000000
   2  2.5000000000000000000000000
   3  2.6666666666666665186369300
   4  2.7083333333333330372738601
   5  2.7166666666666663410012461
   6  2.7180555555555554470004154
   7  2.7182539682539683667528152
   8  2.7182787698412700372330164
   9  2.7182815255731922476911677
  10  2.7182818011463845131459038
  11  2.7182818261984929009145162
  12  2.7182818282861687109175364
  13  2.7182818284467593628050963
  14  2.7182818284582301870955234
  15  2.7182818284589949087148852
  16  2.7182818284590428703495490
  17  2.7182818284590455348848081
  18  2.7182818284590455348848081
  19  2.7182818284590455348848081
  20  2.7182818284590455348848081 

*/

/* A Sample Output Running on Ares/Unix
====================================================================
Harper CSC121-002 by Mr. Jin Guo: Optional #5, Spring 2023
Student: Zach Perkins

This program will calculate the natural number e with factorial:
e = 1/0! + 1/1! + 1/2! + 1/3! + ... + 1/N!

The larger N is, the more precise e will be.
====================================================================

   N    Natural Number e
~~~~  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   0  1.0000000000000000000000000
   1  2.0000000000000000000000000
   2  2.5000000000000000000000000
   3  2.6666666666666666667389468
   4  2.7083333333333333334778936
   5  2.7166666666666666669124192
   6  2.7180555555555555558543135
   7  2.7182539682539682542126297
   8  2.7182787698412698414261041
   9  2.7182815255731922401017525
  10  2.7182818011463844799693174
  11  2.7182818261984928653526850
  12  2.7182818282861685641165622
  13  2.7182818284467590024162942
  14  2.7182818284582297479936436
  15  2.7182818284589944644088350
  16  2.7182818284590422590763642
  17  2.7182818284590450706294379
  18  2.7182818284590452267545507
  19  2.7182818284590452349944872
  20  2.7182818284590452354281681

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

