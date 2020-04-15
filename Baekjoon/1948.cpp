#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Edge {
	int start;
	int cost;
};
int N;
vector<int> indegree, result, c;
vector<vector<struct Edge> > arr, back;
void topologySort(int start, int end)
{
	queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		int size = arr[cur].size();
		for (int i = 0; i < size; i++)
		{
			struct Edge tmp = arr[cur][i];
			if (result[tmp.start] <= tmp.cost + result[cur])
				result[tmp.start] = tmp.cost + result[cur];

			if (--indegree[tmp.start] == 0)
				q.push(tmp.start);
		}
	}

	int cnt = 0;
	q.push(end);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		int size = back[cur].size();
		for (int i = 0; i < size; i++)
		{
			struct Edge tmp = back[cur][i];
			if (result[cur] - result[tmp.start] == tmp.cost)
			{
				cnt++;
				if (c[tmp.start] == 0)
				{
					q.push(tmp.start);
					c[tmp.start] = 1;
				}
			}
		}
	}
	cout << result[end] << '\n' << cnt;
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M, start, end;
	cin >> N >> M;

	indegree.resize(N + 1, 0);
	result.resize(N + 1, 0);
	c.resize(N + 1, 0);
	arr.resize(N + 1);
	back.resize(N + 1);

	int s, e, c;
	for (int i = 0; i < M; i++)
	{
		cin >> s >> e >> c;
		arr[s].push_back({ e, c });
		back[e].push_back({ s, c });
		indegree[e]++;
	}
	cin >> start >> end;
	topologySort(start, end);
}