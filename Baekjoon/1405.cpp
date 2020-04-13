#include <iostream>
#include <vector>
using namespace std;
long double pb[4];
int dir[4][2] =
{
	{1,0},{-1,0},{0,1},{0,-1}
};
int N;
long double ans = 0.0;
vector<vector<bool> > board;
void dfs(int x, int y, int cur, long double prob)
{
	if (!board[y][x])
	{
		if (cur == N)
		{
			ans += prob;
			return;
		}

		board[y][x] = true;
		for (int i = 0; i < 4; i++)
		{
			int dx = x + dir[i][0], dy = y + dir[i][1];
			dfs(dx, dy, cur + 1, prob*pb[i]);
		}
		board[y][x] = false;
	}
}
int main(void)
{
	cin >> N;
	for (int i = 0; i < 4; i++)
	{
		cin >> pb[i];
		pb[i] /= 100.0;
	}
	board.resize(N * 2 + 2, vector<bool>(N * 2 + 2, false));
	dfs(N, N, 0, 1);

	cout.precision(10);
	cout << fixed << ans;
}