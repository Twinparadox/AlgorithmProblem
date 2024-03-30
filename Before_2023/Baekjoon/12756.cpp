#include <iostream>
using namespace std;
int main(void)
{
	int aA, aH, bA, bH, turn1, turn2;
	cin >> aA >> aH >> bA >> bH;
	turn1 = (bH / aA) + (bH%aA ? 1 : 0);
	turn2 = (aH / bA) + (aH%bA ? 1 : 0);
	if (turn1 > turn2)
		cout << "PLAYER B";
	else if (turn1 < turn2)
		cout << "PLAYER A";
	else
		cout << "DRAW";
}
