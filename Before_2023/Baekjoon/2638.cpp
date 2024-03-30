#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int dir[4][2] = {
{1,0},
{0,1},
{-1,0},
{0,-1}
};
int N, M;
vector<vector<int> > curMap;
vector<vector<bool> > visit;
queue<pair<int, int> > qCheese;
bool isEdge(int x, int y)
{
	int cnt = 0;
	for (int i = 0; i < 4; i++)
		if (curMap[x + dir[i][0]][y + dir[i][1]] == -1)
			cnt++;
	if (cnt >= 2)
		return true;
	else
		return false;
}
bool check(int x, int y)
{
	return (x >= 0 && x < N) && (y >= 0 && y < M);
}
void findAir()
{
	vector<vector<bool> > visitAir(N, vector<bool>(M, false));
	visitAir[0][0] = true;
	queue<pair<int, int> > q;
	q.push(make_pair(0, 0));
	while (!q.empty())
	{
		int cx = q.front().first, cy = q.front().second;
		q.pop();
		curMap[cx][cy] = -1;

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dir[i][0], ny = cy + dir[i][1];
			if (check(nx, ny) && !visitAir[nx][ny] && curMap[nx][ny] <= 0)
			{
				q.push(make_pair(nx, ny));
				visitAir[nx][ny] = true;
			}
		}
	}
}
void bfs(int x, int y)
{
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));

	while (!q.empty())
	{
		int cx = q.front().first, cy = q.front().second;
		q.pop();
		visit[cx][cy] = true;

		if (isEdge(cx, cy))
		{
			curMap[cx][cy] = 2;
			qCheese.push(make_pair(cx, cy));
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dir[i][0], ny = cy + dir[i][1];
			if (check(nx, ny) && !visit[nx][ny] && curMap[nx][ny] == 1)
			{
				visit[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}
}
int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> N >> M;
	curMap.resize(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> curMap[i][j];

	for (T = 0; ; T++)
	{
		visit = vector<vector<bool> >(N, vector<bool>(M, false));
		findAir();

		for (int i = 1; i < N - 1; i++)
			for (int j = 1; j < M - 1; j++)
				if (curMap[i][j] == 1 && isEdge(i, j))
					bfs(i, j);

		int cnt = qCheese.size();
		if (!cnt)
			break;

		while (!qCheese.empty())
		{
			int cx = qCheese.front().first, cy = qCheese.front().second;
			qCheese.pop();
			curMap[cx][cy] = -1;
		}
	}

	cout << T;
}