// 이것이 코테다 9-3 C++
// Floyd-Warshall Algorithm
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;
vector<vector<int> > graph;
int N, M;
void floyd()
{
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}
int main(void)
{
	cin >> N >> M;
	graph.resize(N + 1, vector<int>(N + 1, INF));

	for (int i = 1; i <= N; i++)
		graph[i][i] = 0;

	int u, v, w;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> w;
		graph[u][v] = w;
	}

	floyd();
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (graph[i][j] == INF)
				cout << "INF ";
			else
				cout << graph[i][j] << " ";
		}
		cout << '\n';
	}
}