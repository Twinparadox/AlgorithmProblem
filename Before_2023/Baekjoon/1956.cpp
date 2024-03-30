#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e7 + 1;
int n;
vector<vector<int> > graph;
void Floyd()
{
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (graph[i][k] + graph[k][j] < graph[i][j])
					graph[i][j] = graph[i][k] + graph[k][j];
}
int main(void)
{
	int b, v1, v2, w;
	cin >> n;

	graph = vector<vector<int> >(n, vector<int>(n, INF));

	for (int i = 0; i < n; i++)
		graph[i][i] = 0;
	cin >> b;
	for (int i = 0; i < b; i++)
	{
		cin >> v1 >> v2 >> w;
		if (graph[v1 - 1][v2 - 1] > w)
			graph[v1 - 1][v2 - 1] = w;
	}

	Floyd();

	int ans = INF;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (graph[i][j] != INF && graph[j][i] != INF)
			{
				int sub = graph[i][j] + graph[j][i];
				ans = ans < sub ? ans : sub;
			}
		}
	}
	if (ans == INF)
		cout << -1;
	else
		cout << ans;
}