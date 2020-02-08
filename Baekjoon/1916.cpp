#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int INF = 1000000000;
int v, e, src, dest;
vector<vector<pair<int, int> > > graph;
vector<int> dist;
vector<bool> sptSet;
int minDistance()
{
	int min = INF, minIdx = -1;
	for (int i = 0; i < v; i++)
		if (sptSet[i] == false && dist[i] <= min)
			min = dist[i], minIdx = i;

	return minIdx;
}
void Dijkstra(int src, int dest)
{
	for (int i = 0; i < v; i++)
		dist[i] = INF, sptSet[i] = false;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push(make_pair(0, src));
	dist[src] = 0;

	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();

		for (auto i = graph[u].begin(); i != graph[u].end(); ++i)
		{
			int v = (*i).first;
			int weight = (*i).second;

			if (dist[v] > dist[u] + weight)
			{
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}

	cout << dist[dest];
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int start, end, d;
	cin >> v >> e;
	graph = vector<vector<pair<int, int> > >(v);
	sptSet = vector<bool>(v, false);
	dist = vector<int>(v, INF);

	for (int i = 0; i < e; i++)
	{
		cin >> start >> end >> d;
		graph[start - 1].push_back(make_pair(end - 1, d));
	}
	cin >> src >> dest;

	Dijkstra(src - 1, dest - 1);
}