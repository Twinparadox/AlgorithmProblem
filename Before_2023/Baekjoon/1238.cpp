#include <iostream>
#define INF 1000000000
using namespace std;
int graph[1000][1000], n;
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
	int m, x, v1, v2, w, max, weight;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			graph[i][j] = INF;
	for (int i = 0; i < n; i++)
		graph[i][i] = 0;

	cin >> m >> x;
	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2 >> w;
		if(graph[v1-1][v2-1] > w)
			graph[v1 - 1][v2 - 1] = w;
	}

	Floyd();

	max = -1;
	for (int i = 0; i < n; i++)
	{
		weight = graph[i][x - 1] + graph[x - 1][i];
		max = max < weight ? weight : max;
	}
	cout << max;
}
