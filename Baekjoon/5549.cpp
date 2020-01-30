#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct land
{
	int jungle;
	int ocean;
	int ice;
};
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int m, n;
	int k;
	cin >> m >> n >> k;
	vector<string> arr(m + 1);
	vector<vector<struct land> > maps(m + 1, vector<struct land>(n + 1, { 0,0,0 }));

	for (int i = 1; i <= m; i++)
		cin >> arr[i];
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			maps[i][j] = maps[i][j - 1];
			if (arr[i][j - 1] == 'J')
				maps[i][j].jungle++;
			else if (arr[i][j - 1] == 'O')
				maps[i][j].ocean++;
			else
				maps[i][j].ice++;
		}
		for (int j = 1; j <= n; j++)
		{
			maps[i][j].jungle += maps[i - 1][j].jungle;
			maps[i][j].ocean += maps[i - 1][j].ocean;
			maps[i][j].ice += maps[i - 1][j].ice;
		}
	}

	int x1, x2, y1, y2;
	int sj, so, si;
	for (int i = 0; i < k; i++)
	{
		cin >> y1 >> x1 >> y2 >> x2;

		sj = maps[y2][x2].jungle - maps[y1 - 1][x2].jungle - maps[y2][x1 - 1].jungle + maps[y1 - 1][x1 - 1].jungle;
		so = maps[y2][x2].ocean - maps[y1 - 1][x2].ocean - maps[y2][x1 - 1].ocean + maps[y1 - 1][x1 - 1].ocean;
		si = maps[y2][x2].ice - maps[y1 - 1][x2].ice - maps[y2][x1 - 1].ice + maps[y1 - 1][x1 - 1].ice;

		cout << sj << ' ' << so << ' ' << si << '\n';
	}
}