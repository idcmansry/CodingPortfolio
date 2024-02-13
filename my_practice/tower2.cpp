#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

vector<int> discs(3);
vector<int> discs_i(3);

void printTowers(const vector<int>& tower, const int& len);
void setUpTowers(vector<int>& tower);
void locateHighestDiscs(const vector<int>& tower, const int& size);
void moveDisc(vector<int>& tower, int& grab, int& drop);

int main()
{
	int size;
	cout << "how many discs => ";
	cin >> size;
	cout << endl;
	
	int len = log10(size) + 2;
	
	cout << "Building towers" << endl;
	vector<int> A(size * 3);
	printTowers(A, len);
	
	cout << "Initializing Towers" << endl;
	setUpTowers(A);
	
	while(A[2] != 1)
	{
		printTowers(A, len);
		locateHighestDiscs(A, size);
		int grab, drop, grabdrop;
		cout << "Which disc would you like to move and where to? (put as a 2 digit integer)\n";
		cin >> grabdrop;
		grab = grabdrop / 10;
		drop = grabdrop % 10;
		moveDisc(A, grab, drop);
	}
	cout << "\nCongratulations!!! You've complete the Hanoi Towers with " << size << " discs!";
	cout << endl;
}

void printTowers(const vector<int>& tower, const int& len)
{
	cout << endl;
	for (size_t idx = 0; idx < tower.size(); idx++)
	{
		cout << setw(len) << tower[idx];
		if (idx % 3 == 2)
		{
			cout << endl;
		}
	}
	cout << endl;
	cout << setw(len) << 1 << setw(len) << 2 << setw(len) << 3 << "     Rod #" << endl << endl;
}

void setUpTowers(vector<int>& tower)
{
	for (size_t idx = 0; idx < tower.size(); idx++)
	{
		tower[idx * 3] = idx + 1;
	}
}

void locateHighestDiscs(const vector<int>& tower, const int& size)
{
	for (int idx1 = 0; idx1 < 3; idx1++)
	{
		for (int idx2 = idx1; idx2 < size*3; idx2 += 3)
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
	drop -= 1;
	
	if (discs[0] == grab)
	{
		grab = 0;
	}
	else if (discs[1] == grab)
	{
		grab = 1;
	}
	else if (discs[2] == grab)
	{
		grab = 2;
	}
	else
	{
		cout << "\nThis is the dumb bug that i had to fix cause it gave another error" << endl;
		return;
	}
	
	if (grab / 3 != 0 || drop / 3 != 0)
	{
		cout << "\nGrab or Drop is out of range! Please try again" << endl;
		return;
	}
	if (discs[grab] > discs[drop] && discs[drop] != 0)
	{
		cout << "\nYou are trying to put disc " << discs[grab] << " on top of disc " << discs[drop];
		cout << "\nJust a reminder, you need to move discs onto bigger discs" << endl;
		return;
	}
	if (grab == drop)
	{
		cout << "\nYou need to move the disc to a different rod" << endl;
		return;
	}
	if (discs[grab] == 0)
	{
		cout << "\nThe rod you chose does not have any discs" << endl;
		return;
	}
	if (discs[grab] < discs[drop])
	{
		cout << "\nMoving disc " << discs[grab] << " on top of disc " << discs[drop];
		tower[discs_i[grab]] = 0;
		tower[discs_i[drop] - 3] = discs[grab];
		return;
	}
	if (discs[drop] == 0)
	{
		cout << "\nMoving disc " << discs[grab] << " onto rod " << drop + 1;
		tower[discs_i[grab]] = 0;
		tower[discs_i[drop]] = discs[grab];
		return;
	}
}