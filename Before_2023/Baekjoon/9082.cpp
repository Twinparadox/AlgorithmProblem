#include <iostream>
#include <vector>
#include <string>
using namespace std;
int dir[3][2] =
{
	{1,1},{1,0},{1,-1}
};
bool isValid(int x, int N)
{
	return x >= 0 && x < N;
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--)
	{
		int N, res = 0, tmp = 0;
		cin >> N;
		vector<string> board(2);
		for (int i = 0; i < 2; i++)
			cin >> board[i];

		for (int i = 0; i < N; i++)
			if (board[1][i] == '*')
				res++;

		for (int i = 0; i < N; i++)
		{
			if (board[0][i] > '0' && board[0][i] <= '9')
				tmp = board[0][i] - '0';
			else
				continue;

			for (int j = 0; j < 3; j++)
			{
				int ny = dir[j][0], nx = dir[j][1] + i;
				if (!tmp)
					break;

				if (isValid(nx, N) && board[ny][nx] == '*')
					tmp--;
			}

			for (int j = 0; j < 3; j++)
			{
				int ny = dir[j][0], nx = dir[j][1] + i;
				if (!tmp)
					break;

				if (isValid(nx, N) && board[ny][nx] == '#')
				{
					board[ny][nx] = '*';
					res++;
					tmp--;
				}

			}
		}
		cout << res << '\n';
	}
}