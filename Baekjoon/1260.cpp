#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, graph[1001][1001];
bool visit[1001];

void DFS(int num)
{
	cout << num << ' ';
	for (int i = 1; i <= n; i++)
		if (graph[num][i] && !visit[i])
			visit[i] = 1, DFS(i);
}
void BFS(int start)
{
	queue<int> q;

	for (int i = 0; i <= n; i++)
		visit[i] = false;

	q.push(start);
	visit[start] = true;

	while (!q.empty())
	{
		int num = q.front();
		q.pop();

		cout << num << ' ';
		for (int i = 1; i <= n; i++)
			if (graph[num][i] && !visit[i])
				visit[i] = true, q.push(i);
	}
	cout << '\n';
}
int main(void)
{
	int m, start, x, y;
	cin >> n >> m >> start;

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		graph[x][y] = graph[y][x] = 1;
	}

	visit[start] = true;
	DFS(start);
	cout << endl;
	BFS(start);
}
