#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, ans;
vector<vector<int> > board;
vector<vector<bool> > check;
int dir[4][2] =
{
	{1,0},{-1,0},{0,1},{0,-1}
};
bool isValid(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < N;
}
void dfs(int y, int x, int c)
{
	check[y][x] = true;
	board[y][x] = c;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dir[i][0], nx = x + dir[i][1];
		if (isValid(nx, ny) && !check[ny][nx] && board[ny][nx])
			dfs(ny, nx, c);
	}
}
int bfs(int island)
{
	queue<pair<int, int> > q;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (board[y][x] == island)
			{
				check[y][x] = true;
				q.push(make_pair(y, x));
			}
		}
	}

	int sub = 0;
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			int cy = q.front().first;
			int cx = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++)
			{
				int ny = cy + dir[j][0], nx = cx + dir[j][1];
				if (isValid(nx, ny))
				{
					if (board[ny][nx] && board[ny][nx] != island)
						return sub;
					else if (!board[ny][nx] && !check[ny][nx])
					{
						check[ny][nx] = true;
						q.push(make_pair(ny, nx));
					}
				}
			}
		}
		sub++;
	}
	if (sub == 0)
		return N * N;
	else
		return sub;
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	board.resize(N, vector<int>(N, 0));
	check.resize(N, vector<bool>(N, false));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	int island = 1;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			if (board[y][x] && !check[y][x])
				dfs(y, x, island++);

	ans = N * N;
	for (int i = 1; i <= island; i++)
	{
		check.clear();
		check.resize(N, vector<bool>(N, false));
		int sub = bfs(i);
		ans = ans < sub ? ans : sub;
	}
	cout << ans;
}