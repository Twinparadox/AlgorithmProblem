#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(void)
{
	int T, N, M, flag = 1;

	cin >> T;

	while (T--)
	{
		flag = 1;
		cin >> N;
		vector<vector<int > > graph(N, vector<int>());
		vector<int> indegree(N, 0);
		vector<int> result(N);
		vector<int> prevRank(N);
		queue<int> q;

		for (int i = 0; i < N; i++)
			cin >> prevRank[i];

		for (int i = 0; i < N; i++)
		{
			int u = prevRank[i] - 1;
			for (int j = i + 1; j < N; j++)
			{
				int v = prevRank[j] - 1;
				graph[u].push_back(v);
				indegree[v]++;
			}
		}

		cin >> M;
		int u, v;
		for (int i = 0; i < M; i++)
		{
			cin >> u >> v;
			bool check = false;
			int size = graph[u - 1].size();
			for (int j = 0; j < size; j++)
			{
				if (graph[u - 1][j] == v - 1)
				{
					indegree[v - 1]--;
					indegree[u - 1]++;

					graph[u - 1].erase(graph[u - 1].begin() + j);
					graph[v - 1].push_back(u - 1);

					check = true;
					break;
				}
			}

			if (!check)
			{
				int size = graph[v - 1].size();
				for (int j = 0; j < size; j++)
				{
					if (graph[v - 1][j] == u - 1)
					{
						indegree[u - 1]--;
						indegree[v - 1]++;

						graph[v - 1].erase(graph[v - 1].begin() + j);
						graph[u - 1].push_back(v - 1);

						break;
					}
				}
			}
		}

		for (int i = 0; i < N; i++)
			if (indegree[i] == 0)
				q.push(i);

		if (q.size() >= 2)
			flag = 2;
		else
		{
			for (int i = 0; i < N; i++)
			{
				if (q.empty())
				{
					flag = 0;
					break;
				}

				int cur = q.front();
				q.pop();
				result[i] = cur + 1;

				int size = graph[cur].size();
				for (int j = 0; j < size; j++)
					if (--indegree[graph[cur][j]] == 0)
						q.push(graph[cur][j]);
			}
		}

		if (flag == 0)
			cout << "IMPOSSIBLE";
		else if (flag == 2)
			cout << "?";
		else
		{
			for (int i = 0; i < N; i++)
				cout << result[i] << ' ';
		}
		cout << '\n';
	}
}