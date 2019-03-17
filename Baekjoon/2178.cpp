#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int N, M;
vector<vector<int> > maze;
vector<vector<int> > value;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

void bfs(int x, int y)
{
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));

	value[x][y] = 1;
	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dir[i][0], ny = y + dir[i][1];
			if ((nx >= 0 && nx < N) && (ny >= 0 && ny < M) && maze[nx][ny] && !value[nx][ny])
			{
				value[nx][ny] = value[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
}
int main(void)
{
	string str;
	cin >> N >> M;
	maze = vector<vector<int> >(N, vector<int>(M, 0));
	value = vector<vector<int> >(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			maze[i][j] = str[j] - '0';
		}
	}

	bfs(0, 0);
	cout << value[N - 1][M - 1];
}