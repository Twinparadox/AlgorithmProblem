#include <iostream>
using namespace std;
int main(void)
{
	int acard[10], bcard[10], awin = 0, bwin = 0, last = -1;
	for (int i = 0; i < 10; i++)
		cin >> acard[i];
	for (int i = 0; i < 10; i++)
		cin >> bcard[i];

	for (int i = 0; i < 10; i++)
	{
		if (acard[i] > bcard[i])
			awin += 3, last = 0;
		else if (acard[i] == bcard[i])
			awin++, bwin++;
		else
			bwin += 3, last = 1;
	}

	cout << awin << ' ' << bwin << '\n';
	if (last == -1)
		cout << 'D';
	else
	{
		if (awin > bwin)
			cout << 'A';
		else if (awin < bwin)
			cout << 'B';
		else
		{
			if (last == 0)
				cout << 'A';
			else
				cout << 'B';
		}
	}
}
