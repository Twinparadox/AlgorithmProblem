#include <iostream>
using namespace std;
int main(void)
{
	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		int player[2] = { 0, };
		char p1, p2;
		for (int i = 0; i < n; i++)
		{
			cin >> p1 >> p2;
			if (p1 == p2)
				continue;
			else
			{
				if (p1 == 'R')
				{
					if (p2 == 'S')
						player[0]++;
					else
						player[1]++;
				}
				else if (p1 == 'S')
				{
					if (p2 == 'R')
						player[1]++;
					else
						player[0]++;
				}
				else
				{
					if (p2 == 'S')
						player[1]++;
					else
						player[0]++;
				}
			}
		}
		if (player[0] == player[1])
			cout << "TIE\n";
		else if (player[0] > player[1])
			cout << "Player 1\n";
		else
			cout << "Player 2\n";
	}
}
