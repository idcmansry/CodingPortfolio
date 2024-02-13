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

using namespace std;

int main() {
    Bank bank;
    bank.loadData();
    bank.menu();
    bank.saveData();
    return 0;
}