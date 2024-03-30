#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
vector<vector<bool> > check;
vector<vector<int> > maps;
vector<int> mapsArr;
vector<vector<int> > test;
void BFS(int x, int y)
{
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	check[x][y] = true;
	while (!q.empty())
	{
		int cx = q.front().first, cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dir[i][0], ny = cy + dir[i][1];
			if ((nx >= 0 && nx < N) && (ny >= 0 && ny < M) && test[nx][ny] != 1 && check[nx][ny] == false)
			{
				check[nx][ny] = true;
				test[nx][ny] = 2;
				q.push(make_pair(nx, ny));
			}
		}
	}
}
int getArea()
{
	check = vector<vector<bool> >(N, vector<bool>(M, false));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (test[i][j] == 2 && check[i][j] == false)
			{
				BFS(i, j);
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (test[i][j] == 0)
				cnt++;
	return cnt;
}
int main(void)
{
	int ans = 0;
	cin >> N >> M;
	maps = vector<vector<int> >(N, vector<int>(M));
	mapsArr = vector<int>(N*M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> maps[i][j];
			mapsArr[i*M + j] = maps[i][j];
		}
	}

	for (int i = 0; i < N*M; i++)
	{
		if (mapsArr[i] != 0)
			continue;
		for (int j = i + 1; j < N*M; j++)
		{
			if (mapsArr[j] != 0)
				continue;
			for (int k = j + 1; k < N*M; k++)
			{
				if (mapsArr[k] != 0)
					continue;

				test = maps;
				test[i / M][i % M] = 1;
				test[j / M][j % M] = 1;
				test[k / M][k % M] = 1;

				int area = getArea();
				if (ans < area)
					ans = area;
			}
		}
	}
	cout << ans;
}