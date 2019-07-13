#include <iostream>
#define INF 1000000001
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
	int b, v1, v2, w;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			graph[i][j] = INF;
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

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (graph[i][j] == INF)
				cout << "0 ";
			else
				cout << graph[i][j] << ' ';
		}
		cout << '\n';
	}
}