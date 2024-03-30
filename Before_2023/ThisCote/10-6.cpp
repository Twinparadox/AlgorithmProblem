/*
이것이 코테다
Graph - 위상 정렬
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int V, E;
vector<int> indegree;
vector<vector<int> > graph;
void topologySort()
{
	queue<int> q;
	vector<int> result;

	for (int i = 1; i <= V; i++)
		if (!indegree[i])
			q.push(i);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		result.push_back(cur);

		int size = graph[cur].size();
		for (int i = 0; i < size; i++)
		{
			indegree[graph[cur][i]]--;

			if (!indegree[graph[cur][i]])
				q.push(graph[cur][i]);
		}
	}

	int size = result.size();
	for (int i = 0; i < size; i++)
		cout << result[i] << ' ';
}
int main(void)
{
	cin >> V >> E;
	indegree.resize(V + 1, 0);
	graph.resize(V + 1);

	int u, v;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		indegree[v]++;
	}

	topologySort();
}
