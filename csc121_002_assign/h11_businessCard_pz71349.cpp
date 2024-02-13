/*
==================================================================================
Course: Harper CSC121-002 by Mr. Jin Guo, Spring 2023
Student Name: Zach Perkins

Program Name: Classes Name and BusinessCard
Program Description:
	This program defines two classes: Name and BusinessCard. It's very common 
	in IT industry that a programmer is asked to add some new features to 
	an existing software. This is such an exercise. It should also give you 
	more experiences about C++ class construct.
		
Instructions:
	1. Run h11_JG.out and your finished program should perform exactly the same as 
		this one does. See the sample output at the end of this program.
	2. Try to understand the whole program before you do any changes. 
		You are asked to add "job title" as a new data member to the 
		existing BusinessCard class. Here's your to-do list:
		1) Add a string data member jobTitle in class BusinessCard.
		2) Add member functions related to this new data member jobTitle.
		3) Modify the existing member function BusinessCard::toString()
			so that job title will be printed out.
		4) Add your testing code in main() to test your code. Refer to 
			the sample output.
	3. 	Please do not remove any existing code. Add your code to 
		wherever is marked as "Your code below ...". Please follow the given
		code conventions and style.
	4. Submit only your .cpp file and name it properly as usual.

Created: 11/18/2020 by Jin Guo.
Updated: 4/27/2021 by Jin Guo. Some improvements.
Updated: 2/21/2023 by Jin Guo. Minor changes. Adapted for this semester.
==================================================================================
*/
#include <string>
#include <iostream>

using namespace std;

class Name
{
public:
	Name() {} // default constructor.
	Name(string fName, string lName, string mName = "")
		{ setFullName(fName, lName, mName); }

	// Accessors
	string getFirstName() const { return firstName; }
	string getLastName() const { return lastName; }
	string getMiddleName() const { return middleName; }
	string toString() const; // defined after main().

	// Mutators
	void setFirstName(string fName) { firstName = fName.substr(0, nameLength); }
	void setLastName(string lName) { lastName = lName.substr(0, nameLength); }
	void setMiddleName(string mName) { middleName = mName.substr(0, nameLength); }
	void setFullName(string fName, string lName, string mName = ""); // defined after main().

private:
	string firstName;
	string lastName;
	string middleName;

	static const int nameLength{ 10 };
};

// -------------------------------------------------------------------------------
class BusinessCard
{
public:
	BusinessCard() {} // default constructor
	BusinessCard(Name theName, string theEmployer = "", string job = "")
		: name(theName), employer(theEmployer), jobTitle(job) {}

	string getName() const { return name.toString(); }
	string getEmployer() const { return employer; }
	string toString() const; // defined after main().

	void setName(string fName, string lName, string mName = "")
		{ name.setFullName(fName, lName, mName); }; 
	void setEmployer(string theEmployer) { employer = theEmployer; }

	/*
	===============================================================
	Add member functions for job title here.
	<<<<< Your code below ... >>>>>
	===============================================================
	*/
	string getJobTitle() const { return jobTitle; }
	void setJobTitle(string job) { jobTitle = job; }

private:
	Name name;
	string employer;

	/*
	===============================================================
	Add jobTitle as a new data member here.
	<<<<< Your code below ... >>>>>
	===============================================================
	*/
	string jobTitle;
};

int main ()
{
	cout << "==================================================================\n";
	cout << "Harper CSC121-002 by Mr. Jin Guo: Assignment #11, Spring 2023 \n";
	cout << "Student: Zach Perkins\n\n";
	cout << "This program defines and tests classes Name and BusinessCard. \n";
	cout << "==================================================================\n\n";

	cout << ">>> Constructing an empty name object with default constructor ...\n";
	Name name0;
	cout << "name0: " << name0.toString() << endl;

	cout << "\n>>> Setting \"Bill Lee\" to name0 ...\n";
	name0.setFullName("Bill", "Lee");
	cout << "name0: " << name0.toString() << endl;

	cout << "\n>>> Constructing name1 for John Smith ...\n";
	Name name1("John", "Smith");
	cout << name1.toString() << "\n";

	cout << "\n>>> Adding middle name \"Washington\" to John Smith ...\n";
	name1.setMiddleName("Washington");
	cout << name1.getFirstName() << " " << name1.getMiddleName() << " "
		<< name1.getLastName() << "\n";
	cout << name1.toString() << "\n";

	cout << "\n>>> Constructing business card for John Smith ...\n";
	BusinessCard name1Card(name1, "Harper College");
	cout << name1Card.toString();

	cout << "\n<<<<< My code below ... >>>>>\n";
	/*
	===================================================================
	Add your code to test jobTitle. Refer to the sample output.
	<<<<< Your code below ... >>>>>
	===================================================================
	*/	
	cout << ">>> Adding a job title to John Smith ...\n";
	name1Card.setJobTitle( "Chair of Math Department" );
	cout << "... After added a job title for John Smith,\n";
	cout << name1Card.toString();
	
	cout << endl;
}

//====================================================
string Name::toString() const
{
	if (!middleName.empty()) // middleName is not empty.
	{
		string middleInitial = middleName.substr(0, 1) + ".";
		return firstName + " " + middleInitial + " " + lastName;
	}

	return firstName + " " + lastName;
}

void Name::setFullName(string fName, string lName, string mName)
{
	firstName = fName.substr(0, nameLength);
	lastName = lName.substr(0, nameLength);
	middleName = mName.substr(0, nameLength);
}

/*
=============================================================================
<<<< Your code below ... Add your code so jobTitle will be printed out. >>>> 
=============================================================================
*/	
string BusinessCard::toString() const
{
	string output = name.toString() + "\n";

	if (!employer.empty())
		output = output + employer + "\n";
	
	if (!jobTitle.empty())
		output = output + jobTitle + "\n";

	return output;
}

/* A Sample Output
===================================================================
Harper CSC121-002 by Mr. Jin Guo: Assignment #11, Spring 2023
Student: Zach Perkins

This program defines and tests classes Name and BusinessCard.
==================================================================

>>> Constructing an empty name object with default constructor ...
name0:

>>> Setting "Bill Lee" to name0 ...
name0: Bill Lee

>>> Constructing name1 for John Smith ...
John Smith

>>> Adding middle name "Washington" to John Smith ...
John Washington Smith
John W. Smith

>>> Constructing business card for John Smith ...
John W. Smith
Harper College

<<<<< My code below ... >>>>>

>>> Adding a job title to John Smith ...
... After added a job title for John Smith,
John W. Smith
Harper College
Chair of Math Department

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

