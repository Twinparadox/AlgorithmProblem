#include <iostream>
#include <string>
using namespace std;
string board[50];
int n, m;
int countDrawing(int y, int x)
{
	int cnt1 = 0, cnt2 = 0, ret;
	for (int i = y; i < y + 8; i++)
	{
		for (int j = x; j < x + 8; j++)
		{
			if ((i - y + j - x) % 2 == 0)
			{
				if (board[i][j] == 'B')
					cnt1++;
			}
			else
			{
				if (board[i][j] == 'W')
					cnt1++;
			}
		}
	}
	for (int i = y; i < y + 8; i++)
	{
		for (int j = x; j < x + 8; j++)
		{
			if ((i - y + j - x) % 2 == 0)
			{
				if (board[i][j] == 'W')
					cnt2++;
			}
			else
			{
				if (board[i][j] == 'B')
					cnt2++;
			}
		}
	}
	ret = cnt1 < cnt2 ? cnt1 : cnt2;
	return ret;
}
int main(void)
{
	int cnt = 0, min = 65;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> board[i];

	for (int y = 0; y <= n - 8; y++)
	{
		for (int x = 0; x <= m - 8; x++)
		{
			cnt = countDrawing(y, x);
			if (min > cnt)
				min = cnt;
		}
	}
	cout << min;
}
