#include <iostream>
using namespace std;
int board[19][19], boardSize = 19;
int dir[4][2] = { {1,0},{1,1},{0,1},{-1,1} };
int main(void)
{
	int ans1, ans2, ansWin;
	ans1 = ans2 = ansWin = -1;

	for (int i = 0; i < boardSize; i++)
		for (int j = 0; j < boardSize; j++)
			cin >> board[i][j];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			for (int k = 0; k < boardSize; k++)
			{
				if (board[j][k] == 0)
					continue;

				int pj = j - dir[i][0], pk = k - dir[i][1];
				if (board[pj][pk] == board[j][k])
					continue;

				int nj = j, nk = k, cnt = 1;
				while (1)
				{
					nj += dir[i][0];
					nk += dir[i][1];

					if (nj < 0 || nj >= boardSize || nk < 0 || nk >= boardSize)
						break;

					if (board[nj][nk] != board[j][k])
						break;

					cnt++;
				}
				if (cnt == 5)
				{
					ans1 = j;
					ans2 = k;
					ansWin = board[j][k];
				}
			}
		}
	}

	if (ansWin == -1)
		cout << 0;
	else
		cout << ansWin << '\n' << ans1 + 1 << ' ' << ans2 + 1;
}