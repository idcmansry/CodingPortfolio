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

#include <string>
#include <vector>
#include "transaction.h"

using namespace std;

class Account {
private:
    string name;
    vector<Transaction> deposits;
    vector<Transaction> withdrawals;

public:
    Account(string newName);

    string getName();

    void deposit(int amount, int month, int day);

    void withdrawal(int amount, int month, int day);

    int getDeposits();

    int getWithdrawals();

    int getBalance();

    int amountOfDeposits();

    int amountOfWithdrawals();

    int amountOfTransactions();

    vector<Transaction> getAllDeposits();

    vector<Transaction> getAllWithdrawals();
};