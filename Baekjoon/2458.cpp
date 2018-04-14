#include <iostream>
using namespace std;
int graph[500][500], n;
void Floyd()
{
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (graph[i][k] == 1 && graph[k][j] == 1)
					graph[i][j] = 1;
}
int main(void)
{
	int m, v1, v2, w, cnt, ans;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			graph[i][j] = 0;

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2;
		graph[v1 - 1][v2 - 1] = 1;
	}

	Floyd();

	ans = 0;
	for (int i = 0; i < n; i++)
	{
		cnt = 0;
		for (int j = 0; j < n; j++)
			if (i != j)
				cnt += (graph[i][j] + graph[j][i]);

		if (cnt == n - 1)
			ans++;
	}
	cout << ans;
}
