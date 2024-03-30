// Dijkstra with MinHeap
// 이것이 코테다 9-2 예제 C++ 코드로 구현
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int INF = 1e9;
int N, M;
vector<vector<pair<int, int> > > graph;
vector<bool> check;
vector<int> dist;
void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, less<pair<int, int> > > pq;
	pq.push(make_pair(0, start));
	dist[start] = 0;

	while (!pq.empty())
	{
		int weight = pq.top().first, cur = pq.top().second;
		pq.pop();

		if (dist[cur] < weight)
			continue;

		int size = graph[cur].size();
		for (int i = 0; i < size; i++)
		{
			int sum = weight + graph[cur][i].second;
			if (sum < dist[graph[cur][i].first])
			{
				dist[graph[cur][i].first] = sum;
				pq.push(make_pair(sum, graph[cur][i].first));
			}
		}
	}
}
int main(void)
{
	int start;
	cin >> N >> M >> start;

	graph.resize(N + 1);
	check.resize(N + 1, false);
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