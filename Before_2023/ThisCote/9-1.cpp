#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;
int N, M;
vector<vector<pair<int, int> > > graph;
vector<bool> check;
vector<int> dist;
int smallNode()
{
	int minWeight = INF, idx = 0;
	for (int i = 1; i <= N; i++)
		if (dist[i] < minWeight && !check[i])
			minWeight = dist[i], idx = i;
	return idx;
}
void dijkstra(int start)
{
	dist[start] = 0;
	check[start] = true;

	int size = graph[start].size();
	for (int i = 0; i < size; i++)
		dist[graph[start][i].first] = graph[start][i].second;

	for (int i = 0; i < N - 1; i++)
	{
		int cur = smallNode();
		check[cur] = true;

		int size = graph[cur].size();
		for (int j = 0; j < size; j++)
		{
			int weight = dist[cur] + graph[cur][j].second;
			if (weight < dist[graph[cur][j].first])
				dist[graph[cur][j].first] = weight;
		}
	}
}
int main(void)
{
	int start;
	cin >> N >> M >> start;
	graph.resize(N + 1);
	check.resize(N + 1, 0);
	dist.resize(N + 1, INF);

	int u, v, w;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
	}

	dijkstra(start);

	for (int i = 1; i <= N; i++)
	{
		if (dist[i] == INF)
			cout << "INF";
		else
			cout << dist[i];
		cout << '\n';
	}
}
