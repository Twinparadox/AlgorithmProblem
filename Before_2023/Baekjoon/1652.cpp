#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(void)
{
	int n, vertical = 0, horizontal = 0;

	cin >> n;
	vector<string> room(n);
	for (int i = 0; i < n; i++)
		cin >> room[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-1; j++)
		{
			if (room[i][j] == '.' && room[i][j + 1] == '.')
			{
				int k = j + 1;
				for (; k < n; k++)
				{
					if (room[i][k] == 'X')  
					{
						j = k;
						break;
					}
				}

				if (k == n)
					j = n;
				horizontal++;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (room[j][i] == '.' && room[j+1][i] == '.')
			{
				int k = j + 1;
				for (; k < n; k++)
				{
					if (room[k][i] == 'X')
					{
						j = k;
						break;
					}
				}

				if (k == n)
					j = n;
				vertical++;
			}
		}
	}

	cout << horizontal << ' ' << vertical;
}
