#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	vector<vector<int> > board;
	vector<vector<vector<long long> > > dp;

	cin >> N;
	board.resize(N + 2, vector<int>(N + 2, 0));

	dp.resize(3);
	for (int i = 0; i < 3; i++)
		dp[i].resize(N + 2, vector<long long>(N + 2, 0));


	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> board[i][j];

	dp[0][1][2] = 1;

	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			if (!board[y][x + 1])
				dp[0][y][x + 1] += dp[0][y][x] + dp[2][y][x];
			if (!board[y + 1][x])
				dp[1][y + 1][x] += dp[1][y][x] + dp[2][y][x];
			if (!board[y + 1][x + 1] && !board[y][x + 1] && !board[y + 1][x])
				dp[2][y + 1][x + 1] += dp[2][y][x] + dp[1][y][x] + dp[0][y][x];
		}
	}

	cout << dp[2][N][N] + dp[1][N][N] + dp[0][N][N];
}