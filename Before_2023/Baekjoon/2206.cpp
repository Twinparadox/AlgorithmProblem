#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int dir[4][2] =
{
	{1,0}, {0,1}, {-1,0}, {0,-1}
};
int N, M;
vector<vector<int> > board;
vector<vector<vector<int> > > dp;
bool isValid(int y, int x)
{
	return y >= 0 && y < N && x >= 0 && x < M;
}
int BFS(int y, int x)
{
	queue<pair<pair<int, int>, int> > q;
	q.push(make_pair(make_pair(y, x), 1));
	dp[y][x][1] = 1;

	while (!q.empty())
	{
		int y = q.front().first.first, x = q.front().first.second;
		int isBlocked = q.front().second;
		q.pop();

		if (y == N - 1 && x == M - 1)
			return dp[y][x][isBlocked];

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dir[i][0], nx = x + dir[i][1];

			if (isValid(ny, nx))
			{
				if (board[ny][nx] && isBlocked)
				{
					dp[ny][nx][isBlocked - 1] = dp[y][x][isBlocked] + 1;
					q.push(make_pair(make_pair(ny, nx), isBlocked - 1));
				}
				else if (!board[ny][nx] && !dp[ny][nx][isBlocked])
				{
					dp[ny][nx][isBlocked] = dp[y][x][isBlocked] + 1;
					q.push(make_pair(make_pair(ny, nx), isBlocked));
				}
			}
		}
	}

	return -1;
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	string str;
	cin >> N >> M;

	board = vector<vector<int> >(N, vector<int>(M, 0));
	dp = vector<vector<vector<int> > >(N, vector<vector<int> >(M, vector<int>(2, 0)));
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < M; j++)
			board[i][j] = str[j] - '0';
	}

	cout << BFS(0, 0);
}