#include <iostream>
using namespace std;
long long dp[1001][1001] = { 0, };
int main(void)
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		dp[i][1] = 1;
	for (int i = 1; i <= m; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j <= m; j++)
		{
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] + dp[i - 1][j - 1]) % 1000000007;
		}
	}
	cout << dp[n][m];
}
