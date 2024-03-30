#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int r, c, startR, startC, endR, endC;
	string arr[10], next[10];
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		cin >> arr[i];
		next[i] = arr[i];
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if ((char)arr[i][j] == 'X')
			{
				int cnt = 0;
				if (i - 1 < 0)
					cnt++;
				else
					if ((char)arr[i - 1][j] == '.')
						cnt++;
				if (i + 1 >= r)
					cnt++;
				else
					if ((char)arr[i + 1][j] == '.')
						cnt++;

				if (j - 1 < 0)
					cnt++;
				else
					if ((char)arr[i][j - 1] == '.')
						cnt++;
				if (j + 1 >= c)
					cnt++;
				else
					if ((char)arr[i][j + 1] == '.')
						cnt++;
				if (cnt >= 3)
					next[i][j] = '.';
			}
		}
	}

	startR = r - 1, startC = c - 1;
	endR = endC = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (next[i][j] == 'X')
			{
				startR = startR > i ? i : startR;
				startC = startC > j ? j : startC;
				endR = endR < i ? i : endR;
				endC = endC < j ? j : endC;
			}
		}
	}
	for (int i = startR; i <= endR; i++)
	{
		for (int j = startC; j <= endC; j++)
			cout << next[i][j];
		cout << '\n';
	}
}
