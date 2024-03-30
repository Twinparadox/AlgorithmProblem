#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool isValid(int coord, int N)
{
	return coord >= 1 && coord <= N;
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	vector<vector<int> > board;
	vector<vector<long long> > rout;

	cin >> N;
	board.resize(N + 1, vector<int>(N + 1, 0));
	rout.resize(N + 1, vector<long long>(N + 1, 0));
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> board[i][j];

	rout[1][1] = 1;

	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			if (board[y][x] == 0)
				break;
			if (isValid(y + board[y][x], N))
				rout[y + board[y][x]][x] += rout[y][x];
			if (isValid(x + board[y][x], N))
				rout[y][x + board[y][x]] += rout[y][x];
		}
	}

	cout << rout[N][N];
}