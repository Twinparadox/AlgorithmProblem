/*
[P5] 1761 - 정점들의 거리
LCA 문제, Root와의 거리를 기준으로
A 거리, B 거리의 합에 LCA의 거리를 빼주는 식으로 계산 가능
*/
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
const int MAXLEV = (int)floor(log2(4e4 + 1));
vector<int> depth, dist;
vector<vector<int> > ancestor;
vector<vector<pair<int, int> > > graph;
int N, M;
void makeTree(int cur, int parent, int weight)
{
	depth[cur] = depth[parent] + 1;
	ancestor[cur][0] = parent;

	if (cur > 1)
		dist[cur] += dist[parent] + weight;

	for (int i = 1; i <= MAXLEV; i++)
	{
		int other = ancestor[cur][i - 1];
		ancestor[cur][i] = ancestor[other][i - 1];
	}

	int size = graph[cur].size();
	for (int i = 0; i < size; i++)
	{
		int tmp = graph[cur][i].first;
		if (tmp != parent)
			makeTree(tmp, cur, graph[cur][i].second);
	}
}
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N;

	ancestor.resize(N + 1, vector<int>(log2(4e4) + 1, 0));
	graph.resize(N + 1);
	depth.resize(N + 1, 0);
	dist.resize(N + 1, 0);

	depth[0] = -1;
	int u, v, w;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
		graph[v].push_back(make_pair(u, w));
	}

	makeTree(1, 0, 0);

	cin >> M;
	while (M--)
	{
		cin >> u >> v;

		int U = u, V = v;
		if (depth[u] != depth[v])
		{
			if (depth[u] > depth[v])
				swap(u, v);

			for (int i = MAXLEV; i >= 0; i--)
				if (depth[u] <= depth[ancestor[v][i]])
					v = ancestor[v][i];
		}

		int lca = u;
		if (u != v)
		{
			for (int i = MAXLEV; i >= 0; i--)
			{
				if (ancestor[u][i] != ancestor[v][i])
				{
					u = ancestor[u][i];
					v = ancestor[v][i];
				}
				lca = ancestor[u][i];
			}
		}

		cout << dist[U] + dist[V] - 2 * dist[lca] << '\n';
	}
}