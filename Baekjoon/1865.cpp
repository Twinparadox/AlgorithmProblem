#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e7;
int N, M, W;
vector<vector<pair<int, int> > > graph;
bool bellman()
{
	vector<int> dist(N, INF);
	dist[0] = 0;

	bool flag = false;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int size = graph[j].size();
			for (int k = 0; k < size; k++)
			{
				int dst = graph[j][k].first;
				int weight = graph[j][k].second;

				if (dist[dst] > dist[j] + weight)
				{
					dist[dst] = dist[j] + weight;
					if (i == N - 1)
						flag = true;
				}
			}
		}
	}

	if (flag)
		return true;
	else
		return false;
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--)
	{
		cin >> N >> M >> W;
		graph = vector<vector<pair<int, int> > >(N);

		int s, e, w, t;
		for (int i = 0; i < M; i++)
		{
			cin >> s >> e >> w;
			graph[s - 1].push_back(make_pair(e - 1, w));
			graph[e - 1].push_back(make_pair(s - 1, w));
		}
		for (int i = 0; i < W; i++)
		{
			cin >> s >> e >> t;
			graph[s - 1].push_back(make_pair(e - 1, -t));
		}

		if (bellman())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}