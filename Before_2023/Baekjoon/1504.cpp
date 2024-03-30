#include <iostream>
using namespace std;
const int INF = 1e9;
long long graph[1000][1000], n;
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
	int m, v1, v2, w, weight, lay1, lay2;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			graph[i][j] = INF;
	for (int i = 0; i < n; i++)
		graph[i][i] = 0;

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2 >> w;
		graph[v2 - 1][v1 - 1] = graph[v1 - 1][v2 - 1] = w;
	}
	cin >> lay1 >> lay2;

	Floyd();

	long long ans, sub1, sub2;
	sub1 = graph[0][lay1 - 1] + graph[lay1 - 1][lay2 - 1] + graph[lay2 - 1][n - 1];
	sub2 = graph[0][lay2 - 1] + graph[lay2 - 1][lay1 - 1] + graph[lay1 - 1][n - 1];
	ans = sub1 < sub2 ? sub1 : sub2;
	if (ans >= INF)
		cout << -1;
	else
		cout << ans;
}