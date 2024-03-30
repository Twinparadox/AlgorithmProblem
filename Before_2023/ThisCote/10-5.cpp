/*
이것이 코테다
Graph - Kruskal
Union-Find & Greedy로 해결
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct edge
{
	int source, dest, weight;
};
int V, E;
vector<int> parent;
vector<edge> graph;
bool compare(edge a, edge b)
{
	return a.weight < b.weight;
}
int findParent(int x)
{
	if (parent[x] != x)
		return parent[x] = findParent(parent[x]);
	return parent[x];
}
void unionParent(int a, int b)
{
	a = findParent(a);
	b = findParent(b);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}
int Kruskal()
{
	int size = graph.size();
	int src, dst, weight, ans = 0;

	for (int i = 0; i < size; i++)
	{
		if (findParent(src) != findParent(dst))
		{
			unionParent(src, dst);
			ans += weight;
		}
	}

	return ans;
}
int main(void)
{
	cin >> V >> E;
	parent.resize(V + 1, 0);

	for (int i = 1; i <= V; i++)
		parent[i] = i;

	int u, v, w;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		graph.push_back({ u,v,w });
	}
	sort(graph.begin(), graph.end(), compare);

	cout << Kruskal();
}