#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int M, N, K;
vector<vector<int> > ground;
vector<vector<bool> > check;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

void bfs(int x, int y)
{
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));

	check[x][y] = true;
	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dir[i][0], ny = y + dir[i][1];
			if ((nx >= 0 && nx < M) && (ny >= 0 && ny < N) && ground[nx][ny] && !check[nx][ny])
			{
				q.push(make_pair(nx, ny));
				check[nx][ny] = true;
			}
		}
	}
}
int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> M >> N >> K;
		ground = vector<vector<int> >(M, vector<int>(N, 0));
		check = vector<vector<bool> >(M, vector<bool>(N, false));

		int x, y;
		for (int i = 0; i < K; i++)
		{
			cin >> x >> y;
			ground[x][y] = 1;
		}

		int bug = 0;
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (ground[i][j] && !check[i][j])
				{
					bug++;
					bfs(i, j);
				}
			}
		}

		cout << bug << '\n';
	}
}