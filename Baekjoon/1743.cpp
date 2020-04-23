#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, K, ans = 0;
vector<vector<int> > board;
vector<vector<bool> > isCheck;
int dir[4][2] =
{
	{1,0},{-1,0},{0,1},{0,-1}
};
bool isValid(int x, int y)
{
	return y >= 1 && y <= N && x >= 1 && x <= M;
}
int bfs(int y, int x)
{
	int cnt = 0;
	queue<pair<int, int> > q;
	q.push(make_pair(y, x));
	while (!q.empty())
	{
		int cy = q.front().first, cx = q.front().second;
		isCheck[cy][cx] = true;
		q.pop();
		cnt++;

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dir[i][0], nx = cx + dir[i][1];
			if (isValid(nx, ny) && board[ny][nx] && !isCheck[ny][nx])
			{
				q.push(make_pair(ny, nx));
				isCheck[ny][nx] = true;
			}
		}
	}
	return cnt;
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> K;
	board.resize(N + 1, vector<int>(M + 1, 0));
	isCheck.resize(N + 1, vector<bool>(M + 1, false));

	int x, y;
	for (int i = 0; i < K; i++)
	{
		cin >> y >> x;
		board[y][x] = 1;
	}

	int sub = 0;
	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= M; x++)
		{
			if (board[y][x] && !isCheck[y][x])
			{
				sub = bfs(y, x);
				ans = ans < sub ? sub : ans;
			}
		}
	}
	cout << ans;
}