#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int> > graph;
vector<int> colors;
bool isBipartite = false;
const int T1 = 1, T2 = -1;
void bfs(int vert, int type)
{
	queue<int> q;
	q.push(vert);
	colors[vert] = type;

	while (!q.empty() && isBipartite)
	{
		int cur = q.front();
		q.pop();

		int size = graph[cur].size();
		for (int i = 0; i < size; i++)
		{
			if (!colors[graph[cur][i]])
			{
				q.push(graph[cur][i]);
				colors[graph[cur][i]] = colors[cur] * -1;
			}
			else if (colors[cur] + colors[graph[cur][i]] != 0)
			{
				isBipartite = false;
				break;
			}
		}
	}
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int T, V, E;
	cin >> T;
	while (T--)
	{
		cin >> V >> E;

		isBipartite = true;
		graph = vector<vector<int> >(V + 1);
		colors = vector<int>(V + 1, 0);

		int u, v;
		for (int i = 0; i < E; i++)
		{
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		for (int i = 1; i <= V; i++)
		{
			if (!isBipartite)
				break;

			if (!colors[i])
			{
				bfs(i, T1);
			}
		}

		if (isBipartite)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}