#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() 
{
	for (int height = 9; height >= 1; height--)
	{
		cout << setw(11 - height);
		for (int width = 1; width <= height; width++)
		{
			cout << "* ";
		}
		cout << endl;
	}
}