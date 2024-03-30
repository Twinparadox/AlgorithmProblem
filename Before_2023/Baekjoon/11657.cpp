#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
struct Edge
{
	int src, dest, weight;
};
int V, E;
vector<struct Edge> edge;

void printArr(vector<long long>& dist)
{
	for (int i = 2; i <= V; i++)
	{
		if (dist[i] == INT_MAX)
			cout << -1;
		else
			cout << dist[i];
		cout << '\n';
	}
}
void BellmanFord(int src)
{
	bool flag = true;
	vector<long long> dist;
	dist.resize(V + 1);

	for (int i = 1; i <= V; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

	for (int i = 1; i <= V - 1; i++)
	{
		for (int j = 0; j < E; j++)
		{
			int u = edge[j].src;
			int v = edge[j].dest;
			long long weight = edge[j].weight;
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
			{
				dist[v] = dist[u] + weight;
				if (i == V)
					flag = false;
			}
		}
	}
	for (int j = 0; j < E; j++)
	{
		int u = edge[j].src;
		int v = edge[j].dest;
		long long w = edge[j].weight;
		if (dist[u] != INT_MAX && dist[u] + w < dist[v])
		{
			flag = false;
			break;
		}
	}

	if (flag)
		printArr(dist);
	else
		cout << -1;
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int A, B, C;
	cin >> V >> E;

	edge.resize(E);
	for (int i = 0; i < E; i++)
		cin >> edge[i].src >> edge[i].dest >> edge[i].weight;
	BellmanFord(1);

	return 0;
}
