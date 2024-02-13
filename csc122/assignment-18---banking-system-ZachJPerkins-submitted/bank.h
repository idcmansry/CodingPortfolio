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

#include <vector>
#include "account.h"

using namespace std;

class Bank {
private:
    vector<Account> accountInfo;

public:
    Bank();

    void menu();

    void createAccount();

    int chooseAccount();

    void manageAccount(int accountIndex);

    void printAccounts();

    void printTransactions(int accountIndex);

    void loadData();

    void saveData();
};