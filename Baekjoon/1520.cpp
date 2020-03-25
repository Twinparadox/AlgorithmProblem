#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<vector<int> > board, dp;
int dir[4][2] =
{
	{1,0},{0,1},{-1,0},{0,-1}
};
bool isValid(int x, int y)
{
	return y >= 0 && y < M && x >= 0 && x < N;
}
int dfs(int x, int y)
{
	if (dp[y][x] != -1)
		return dp[y][x];
	else if (y == 0 && x == 0)
		return 1;

	dp[y][x] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dir[i][0], ny = y + dir[i][1];
		if (isValid(nx, ny) && board[ny][nx] > board[y][x])
			dp[y][x] += dfs(nx, ny);
	}
	return dp[y][x];
}
int main(void)
{
	cin >> M >> N;
	board = vector<vector<int> >(M, vector<int>(N, 0));
	dp = vector<vector<int> >(M, vector<int>(N, -1));

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	cout << dfs(N - 1, M - 1);
}