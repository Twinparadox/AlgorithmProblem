#include <iostream>
using namespace std;
int main(void)
{
	int n, m, x, y, cnt = 0;
	int g[501][501] = { 0, };
	bool check[501] = { false,true, };
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		g[x][y] = 1;
	}
	for (int i = 2; i <= n; i++)
		if (g[1][i] || g[i][1])
			for (int j = 1; j <= n; j++)
				if (g[i][j] || g[j][i])
					check[i] = check[j] = true;
	for (int i = 2; i <= n; i++)
		if (check[i])
			cnt++;
	cout << cnt;
}
