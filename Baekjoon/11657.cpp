#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
struct Edge
{
	int src, dest, weight;
};
struct Graph
{
	int V, E;
	vector<struct Edge> edge;
};
struct Graph graph;

void printArr(vector<int>& dist, int n)
{
	for (int i = 1; i < n; ++i)
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
	int V = graph.V;
	int E = graph.E;
	vector<int> dist(V);

	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

	for (int i = 1; i <= V - 1; i++)
	{
		for (int j = 0; j < E; j++)
		{
			int u = graph.edge[j].src;
			int v = graph.edge[j].dest;
			int weight = graph.edge[j].weight;
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight;
		}
	}

	for (int i = 0; i < E; i++)
	{
		int u = graph.edge[i].src;
		int v = graph.edge[i].dest;
		int weight = graph.edge[i].weight;
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
		{
			cout << -1;
			return;
		}
	}

	printArr(dist, V);
	return;
}
int main(void)
{
	int V, E, A, B, C;
	cin >> V >> E;

	graph.V = V;
	graph.E = E;
	graph.edge = vector<struct Edge>(E);
	for (int i = 0; i < E; i++)
	{
		cin >> A >> B >> C;
		graph.edge[i] = { A - 1,B - 1,C };
	}
	BellmanFord(0);
}
