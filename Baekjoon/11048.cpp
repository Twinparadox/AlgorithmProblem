#include <iostream>
using namespace std;
int arr[1001][1001], dp[1001][1001] = { 0, };
int main(void)
{
	int n, m, max;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];

	for (int i = 1; i <= n; i++)
		dp[i][1] = dp[i - 1][1] + arr[i][1];
	for (int i = 1; i <= m; i++)
		dp[1][i] = dp[1][i - 1] + arr[1][i];

	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j <= m; j++)
		{
			max = dp[i - 1][j] < dp[i][j - 1] ? dp[i][j - 1] : dp[i - 1][j];
			max = max < dp[i - 1][j - 1] ? dp[i - 1][j - 1] : max;
			dp[i][j] = max + arr[i][j];
		}
	}
	cout << dp[n][m];
}
