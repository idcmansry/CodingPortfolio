//***************************************************************************
//
// Zach Perkins
// H00848798
// CSC 122 W01
//
// I certify that this is my own work and where appropriate an extension
// of the starter code provided for the assignment.
//***************************************************************************

#include "bank.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <limits>

Bank::Bank() {}

void Bank::menu() {
    cout << "\nWelcome to Zach Bank!\n" << endl;
    cout << "1. Create Account" << endl;
    cout << "2. Manage Account" << endl;
    cout << "3. Print all Account Info" << endl;
    cout << "4. Exit" << endl;
    int choice;
    while (true) {
        cout << "Enter your choice (1-4): ";
        if (cin >> choice) {
            if (choice >= 1 && choice <= 4) {
                break;
            } else {
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } else {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    switch (choice) {
        case 1:
            createAccount();
            menu();
            break;
        case 2:
            manageAccount(chooseAccount());
            menu();
            break;
        case 3:
            printAccounts();
            menu();
            break;
        case 4:
            break;
        default:
            menu();
            break;
    }
}

void Bank::createAccount() {
    string name;
    cout << "Account Name: ";
    getline(cin, name);
    while (name.empty()) {
        cout << "Account Name cannot be empty. Please enter a valid name: ";
        getline(cin, name);
    }
    Account current(name);
    accountInfo.push_back(current);
}

int Bank::chooseAccount() {
    cout << "Accounts:" << endl;
    for (int idx = 0; idx < accountInfo.size(); idx++) {
        cout << idx + 1 << ". " << accountInfo[idx].getName() << endl;
    }
    cout << "Please pick account number: ";
    int choice;
    while (true) {
        cout << "Enter your choice (1-" << accountInfo.size() << "): ";
        if (cin >> choice) {
            if (choice >= 1 && choice <= accountInfo.size()) {
                break;
            } else {
                cout << "Invalid choice. Please enter a number between 1 and " << accountInfo.size() << "." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } else {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return choice - 1;
}

void Bank::manageAccount(int accountIndex) {
    Account& current = accountInfo[accountIndex];
    cout << "Account for " << current.getName() << endl;
    cout << "1. Deposit" << endl;
    cout << "2. Withdraw" << endl;
    cout << "3. Get Balance" << endl;
    cout << "4. List Transactions" << endl;
    cout << "5. Exit to Menu" << endl;
    int choice;
    while (true) {
        cout << "Enter your choice (1-5): ";
        if (cin >> choice) {
            if (choice >= 1 && choice <= 5) {
                break;
            } else {
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } else {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    cout << endl;
    switch (choice) {
        case 1: {
            int amount;
            while (true) {
                cout << "Enter amount to deposit: ";
                if (cin >> amount) {
                    if (amount > 0) {
                        break;
                    } else {
                        cout << "Invalid amount. Please enter a positive number." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } else {
                    cout << "Invalid input. Please enter a valid number." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            cout << endl;
            current.deposit(amount, 12, 25);
            break;
        }
        case 2: {
            int amount;
            while (true) {
                cout << "Enter amount to withdraw: ";
                if (cin >> amount) {
                    if (amount > 0) {
                        break;
                    } else {
                        cout << "Invalid amount. Please enter a positive number." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } else {
                    cout << "Invalid input. Please enter a valid number." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            cout << endl;
            current.withdrawal(amount, 12, 25);
            break;
        }
        case 3:
            cout << "Account Balance: $" << current.getBalance() << endl;
            break;
        case 4:
            printTransactions(accountIndex);
            break;
        case 5:
            break;
        default:
            cout << "Invalid choice. Please try again." << endl << endl;
            manageAccount(accountIndex);
            break;
    }
}

void Bank::printAccounts() {
    for (Account current : accountInfo) {
        cout << "Account Name: " << current.getName() << endl;
        cout << "Balance: $" << current.getBalance() << endl;
        cout << "Number of Transactions: " << current.amountOfTransactions() << endl;
        cout << "Total Deposits: $" << current.getDeposits() << endl;
        cout << "Total Withdrawals: $" << current.getWithdrawals() << endl;
        double averageTransaction = static_cast<double>(current.getBalance()) / current.amountOfTransactions();
        cout << "Average Transaction: $" << averageTransaction << endl;
        cout << endl;
    }
}

void Bank::printTransactions(int accountIndex) {
    Account& current = accountInfo[accountIndex];
    vector<Transaction> deposits = current.getAllDeposits();
    cout << "Deposits: " << endl << endl;
    for (Transaction current : deposits) {
        current.print();
    }
    cout << endl;

    vector<Transaction> withdrawals = current.getAllWithdrawals();
    cout << "Withdrawals: " << endl << endl;
    for (Transaction current : withdrawals) {
        current.print();
    }
    cout << endl << endl;
}

void Bank::loadData()
{
    ifstream inFile("account.txt");

    if (inFile.is_open())
    {
        string line;
        string name;
        int amount, month, day;

        while (getline(inFile, line))
        {
            if (line.empty())
            {
                // Skip empty lines
                continue;
            }

            // Use stringstream to parse the line
            istringstream iss(line);

            if (line.front() == '{')
            {
                // Account transactions start with '{'
                if (accountInfo.empty())
                {
                    cout << "Warning: Encountered transaction data without an account name. Ignoring transactions." << endl;
                }
                else
                {
                    while (getline(inFile, line) && line.front() != '}')
                    {
                        // Extract transaction details from line
                        istringstream iss(line);
                        if (iss >> amount >> month >> day)
                        {
                            if (amount >= 0)
                            {
                                accountInfo.back().deposit(amount, month, day);
                            }
                            else
                            {
                                accountInfo.back().withdrawal(-amount, month, day);
                            }
                        }
                        else
                        {
                            // Invalid transaction format, ignore the line
                            cout << "Warning: Invalid transaction format in account.txt. Ignoring line: " << line << endl;
                        }
                    }
                }
            }
            else
            {
                // Line contains the account name
                name = line;
                accountInfo.push_back(Account(name));
            }
        }
        inFile.close();
    }
    else
    {
        cout << "No existing account.txt file. Continue without error." << endl;
    }
}

void Bank::saveData()
{
    ofstream outFile("account.txt");

    if (outFile.is_open())
    {
        for (Account& account : accountInfo)
        {
            outFile << account.getName() << "\n";

            outFile << "{\n";
            vector<Transaction> deposits = account.getAllDeposits();
            for (Transaction& deposit : deposits)
            {
                outFile << "    " << deposit.getAmmount() << " " << deposit.getMonth() << " " << deposit.getDate() << "\n";
            }

            vector<Transaction> withdrawals = account.getAllWithdrawals();
            for (Transaction& withdrawal : withdrawals)
            {
                outFile << "    -" << withdrawal.getAmmount() << " " << withdrawal.getMonth() << " " << withdrawal.getDate() << "\n";
            }
            outFile << "}\n";
        }
        outFile.close();
    }
    else
    {
        cout << "Error: Unable to open account.txt for saving data." << endl;
    }
}