#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N, L, ans = 1e9 + 1, maxCost = 1e9 + 1;
	cin >> N;

	vector<vector<int> > arr(N + 1, vector<int>(4));
	vector<vector<int> > dp(N + 1, vector<int>(4));

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= 3; j++)
			cin >> arr[i][j];

	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			if (i == j)
				dp[1][j] = arr[1][j];
			else
				dp[1][j] = maxCost;
		}
		for (int j = 2; j <= N; j++)
		{
			dp[j][1] = min(dp[j - 1][2], dp[j - 1][3]) + arr[j][1];
			dp[j][2] = min(dp[j - 1][1], dp[j - 1][3]) + arr[j][2];
			dp[j][3] = min(dp[j - 1][1], dp[j - 1][2]) + arr[j][3];
		}
		for (int j = 1; j <= 3; j++)
		{
			if (i == j)
				continue;
			ans = min(ans, dp[N][j]);
		}
	}
	cout << ans;
}