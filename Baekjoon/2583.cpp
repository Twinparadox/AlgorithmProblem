#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M, K;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
vector<vector<int> > area;
int BFS(int x, int y)
{
	int cnt = 0;
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	area[x][y] = -1;
	cnt++;
	while (!q.empty())
	{
		int cx = q.front().first, cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dir[i][0], ny = cy + dir[i][1];
			if ((nx >= 0 && nx < N) && (ny >= 0 && ny < M) && area[nx][ny] == 0)
			{
				q.push(make_pair(nx, ny));
				cnt++;
				area[nx][ny] = -1;
			}
		}
	}
	return cnt;
}
int main(void)
{
	cin >> M >> N >> K;
	area = vector<vector<int> >(N, vector<int>(M, 0));

	int x1, y1, x2, y2;
	for (int i = 0; i < K; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		for (int x = x1; x < x2; x++)
		{
			for (int y = y1; y < y2; y++)
			{
				area[x][y] = 1;
			}
		}
	}

	vector<int> sector;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (area[i][j] == 0)
			{
				sector.push_back(BFS(i, j));
			}
		}
	}
	sort(sector.begin(), sector.end());

	cout << sector.size() << '\n';
	for (vector<int>::iterator it = sector.begin(); it != sector.end(); it++)
	{
		cout << *it << ' ';
	}
}