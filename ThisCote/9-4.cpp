/*
이것이 코테다
Floyd-Warshall - 미래 도시
Floyd-Warshall의 Weight를 1로 두고 계산만 하면 되는 문제
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;
vector<vector<int> > graph;
int N, M;
void floyd()
{
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}
int main(void)
{
	int K, X;
	cin >> N >> M;
	graph.resize(N + 1, vector<int>(N + 1, INF));

	for (int i = 1; i <= N; i++)
		graph[i][i] = 0;

	int u, v, w;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		graph[u][v] = graph[v][u] = 1;
	}
	cin >> X >> K;

	floyd();


	int ans = graph[1][K] + graph[K][X];

	if (ans >= INF)
		cout << -1;
	else
		cout << ans;
}