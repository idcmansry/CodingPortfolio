//***************************************************************************
//
// Zach Perkins
// H00848798
// CSC 122 W01
//
// I certify that this is my own work and where appropriate an extension
// of the starter code provided for the assignment.
//***************************************************************************

#include "account.h"

Account::Account(string newName) : name(newName) {}

string Account::getName() {
    return name;
}

void Account::deposit(int ammount, int month, int day) {
    deposits.push_back(Transaction(ammount, month, day));
}

void Account::withdrawal(int ammount, int month, int day) {
    withdrawals.push_back(Transaction(ammount, month, day));
}

int Account::getDeposits() {
    int balance = 0;
    for (Transaction deposit : deposits) {
        balance += deposit.getAmmount();
    }
    return balance;
}

int Account::getWithdrawals() {
    int balance = 0;
    for (Transaction withdrawal : withdrawals) {
        balance += withdrawal.getAmmount();
    }
    return balance;
}

int Account::getBalance() {
    int balance = 0;
    balance += getDeposits();
    balance -= getWithdrawals();
    return balance;
}

int Account::amountOfDeposits() {
    return deposits.size();
}

int Account::amountOfWithdrawals() {
    return withdrawals.size();
}

int Account::amountOfTransactions() {
    return amountOfDeposits() + amountOfWithdrawals();
}

vector<Transaction> Account::getAllDeposits() {
    return deposits;
}

vector<Transaction> Account::getAllWithdrawals() {
    return withdrawals;
}