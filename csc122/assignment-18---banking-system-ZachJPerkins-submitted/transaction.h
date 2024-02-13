//***************************************************************************
//
// Zach Perkins
// H00848798
// CSC 122 W01
//
// I certify that this is my own work and where appropriate an extension
// of the starter code provided for the assignment.
//***************************************************************************

#pragma once

using namespace std;

class Transaction
{
    private:
        int monthOfTransaction;
        int dateOfTransaction;
        int ammountOfTransaction;
    
    public:
        Transaction(int ammount, int month, int day);
        void print();
        int getMonth();
        int getDate();
        int getAmmount();
};