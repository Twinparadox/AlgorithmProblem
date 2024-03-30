#include <iostream>
#define INF 1000000000
using namespace std;
int graph[100][100], n;
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
	int m, v1, v2, w, cnt, min, sum, ans;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			graph[i][j] = INF;
	// D[i][i]=0
	for (int i = 0; i < n; i++)
		graph[i][i] = 0;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2;
		graph[v2 - 1][v1 - 1] = graph[v1 - 1][v2 - 1] = 1;
	}

	Floyd();

	min = 5001;
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		for (int j = 0; j < n; j++)
			sum += graph[i][j];
		if (min > sum)
			min = sum, ans = i + 1;
	}
	cout << ans;
}
