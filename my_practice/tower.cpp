#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

vector<int> discs(3);
vector<int> discs_i(3);
int plays = 0;


void printTowers(const vector<int>& tower);
void setUpTowers(vector<int>& tower);
void locateHighestDiscs(const vector<int>& tower);
void moveDisc(vector<int>& tower, int& grab, int& drop);
void moveDisc2(vector<int>& tower, int& grab, int& drop);
void solveTowers(vector<int>& tower, int sizeStack, int init = 0, int mid = 1, int fin = 2);
void printGraphics(const vector<int>& tower);
void playTowers(vector<int>& tower);

int main()
{
	cout << "---------------------------------------------\n\n";
	cout << "Welcome to the Towers of Hanoi\n";
	cout << "Made by Zach Perkins\n\n";
	cout << "---------------------------------------------\n\n";
	
	int size;
	cout << "How many discs would you like to use? ==> ";
	cin >> size;
	vector<int> tower(size * 3);
	setUpTowers(tower);
	
	cout << "Would you like to play or use the autosolver?\nSelect 0 for play OR 1 for autosolver ==> ";
	bool choice;
	cin >> choice;
	
	if (choice)
	{
		solveTowers(tower, size);
	}
	else
	{
		playTowers(tower);
		cout << "\nYou beat the Towers of Hanoi!!!";
		if (plays == pow(2,size) - 1)
		{
			cout << "\nYou played a perfect game! Congrats!";
		}
	}

	cout << endl;
}
/*
void printTowers(const vector<int>& tower)
{
	cout << endl;
	for (size_t idx = 0; idx < tower.size(); idx++)
	{
		cout << setw(3) << tower[idx];
		if (idx % 3 == 2)
		{
			cout << endl;
		}
	}
	cout << endl;
	cout << setw(3) << 1 << setw(3) << 2 << setw(3) << 3 << "     Rod #" << endl << endl;
}
*/
void setUpTowers(vector<int>& tower)
{
	for (size_t idx = 0; idx < tower.size(); idx++)
	{
		tower[idx * 3] = idx + 1;
	}
}

void locateHighestDiscs(const vector<int>& tower)
{
	for (int idx1 = 0; idx1 < 3; idx1++)
	{
		for (int idx2 = idx1; idx2 < tower.size(); idx2 += 3)
		{
			discs[idx1] = tower[idx2];
			discs_i[idx1] = idx2;
			if (tower[idx2] != 0)
			{
				break;
			}
		}
	}
	cout << endl;
}

void moveDisc(vector<int>& tower, int& grab, int& drop)
{
	locateHighestDiscs(tower);
	drop -= 1;
	grab -= 1;
	
	if (grab / 3 != 0 || drop / 3 != 0)
	{
		cout << "\nGrab or Drop is out of range! Please try again" << endl;
	}
	else if (discs[grab] > discs[drop] && discs[drop] != 0)
	{
		cout << "\nYou are trying to put disc " << discs[grab] << " on top of disc " << discs[drop];
		cout << "\nJust a reminder, you need to move discs onto bigger discs" << endl;
	}
	else if (grab == drop)
	{
		cout << "\nYou need to move the disc to a different rod" << endl;
	}
	else if (discs[grab] == 0)
	{
		cout << "\nThe rod you chose does not have any discs" << endl;
	}
	else if (discs[grab] < discs[drop])
	{
		tower[discs_i[grab]] = 0;
		tower[discs_i[drop] - 3] = discs[grab];
	}
	else if (discs[drop] == 0)
	{
		tower[discs_i[grab]] = 0;
		tower[discs_i[drop]] = discs[grab];
	}
}

void moveDisc2(vector<int>& tower, int& grab, int& drop)
{
	locateHighestDiscs(tower);
	if (discs[grab] < discs[drop])
	{
		tower[discs_i[grab]] = 0;
		tower[discs_i[drop] - 3] = discs[grab];
	}
	else if (discs[drop] == 0)
	{
		tower[discs_i[grab]] = 0;
		tower[discs_i[drop]] = discs[grab];
	}
	printGraphics(tower);
}

void solveTowers(vector<int>& tower, int sizeStack, int init, int mid, int fin)
{
	if (sizeStack == 1)
	{
		moveDisc2(tower, init, fin);
		return;
	}
	solveTowers(tower, sizeStack - 1, init, fin, mid);
	moveDisc2(tower, init, fin);
	solveTowers(tower, sizeStack - 1, mid, init, fin);
}

void printGraphics(const vector<int>& tower)
{
	for (int idx1 = 0; idx1 < tower.size(); idx1 += 3)
	{
		for (int idx2 = idx1; idx2 < idx1 + 3; idx2++)
		{
			cout.width(tower.size() / 3 - tower[idx2] + 1);
			cout << ' ';
			cout.width(tower[idx2] + 1);
			cout.fill('(');
			cout << right << ' ';
			cout << "||";
			cout.width(tower[idx2] + 1);
			cout.fill(')');
			cout << left << ' ';
			cout.width(tower.size() / 3 - tower[idx2] + 1);
			cout.fill(' ');
			cout << ' ';
			cout << "  ";
		} 
		cout << endl;
	}
}

void playTowers(vector<int>& tower)
{
	while(tower[2] != 1)
	{
		printGraphics(tower);
		cout << "Type as a 2 digit number the rod you are taking from and the rod you are putting the disc on\n";
		int move, grab, drop;
		cin >> move;
		grab = move / 10;
		drop = move % 10;
		moveDisc(tower, grab, drop);
		plays++;
	}
	printGraphics(tower);
}