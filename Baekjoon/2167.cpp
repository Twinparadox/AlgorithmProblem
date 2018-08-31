#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	vector<vector<int> > arr;
	vector<vector<int> > dp;
	int n, m, t, x1, y1, x2, y2;

	cin >> n >> m;
	arr.assign(n + 1, vector<int>(m + 1));
	dp.assign(n + 1, vector<int>(m + 1, 0));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> arr[i][j];
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
		}
	}

	cin >> t;
	while (t--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		cout << dp[x2][y2] - (dp[x1 - 1][y2] + dp[x2][y1 - 1] - dp[x1 - 1][y1 - 1]) << '\n';
	}
}
