#include <iostream>
#include <vector>
using namespace std;
int dir[4][2] = {
{0,-1},
{1,0},
{0,1},
{-1,0}
};
vector<vector<int> > board;
int N, M, ans = 0;
void dfs(int x, int y, int d)
{
	if (board[y][x] == 1)
		return;
	if (board[y][x] == 0)
		board[y][x] = -1, ans++;

	for (int i = 0; i <= 3; i++)
	{
		int idx = d - 1 < 0 ? (4 + d - 1) : d - 1;
		int nx = x + dir[idx][0], ny = y + dir[idx][1];
		if (board[ny][nx] == 0)
		{
			dfs(nx, ny, idx);
			return;
		}
		else
		{
			d = idx;
		}
	}

	int backX = x + dir[(d + 2) % 4][0];
	int backY = y + dir[(d + 2) % 4][1];
	dfs(backX, backY, d);
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int r, c, d;
	cin >> N >> M;
	cin >> r >> c >> d;
	board = vector<vector<int> >(N, vector<int>(M, 0));

	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> board[y][x];

	dfs(c, r, d);
	cout << ans;
}