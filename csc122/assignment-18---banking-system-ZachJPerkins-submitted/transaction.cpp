//***************************************************************************
//
// Zach Perkins
// H00848798
// CSC 122 W01
//
// I certify that this is my own work and where appropriate an extension
// of the starter code provided for the assignment.
//***************************************************************************

#include <iostream>
#include "transaction.h"

Transaction::Transaction(int ammount, int month, int day)
{
    ammountOfTransaction = ammount;
    monthOfTransaction = month;
    dateOfTransaction = day;
}

void Transaction::print()
{
    cout << "Transaction:" << endl;
    cout << "Amount: $" << ammountOfTransaction << endl;
    cout << "Date: " << monthOfTransaction << "/" << dateOfTransaction << endl;
    cout << endl;
}

int Transaction::getMonth() { return monthOfTransaction; }
int Transaction::getDate() { return dateOfTransaction; }
int Transaction::getAmmount() { return ammountOfTransaction; }