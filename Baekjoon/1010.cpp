#include <iostream>
using namespace std;
int main(void)
{
	int t, n, m;
	long long dp[31][31] = { 0, };
	cin >> t;

	for (int i = 0; i <= 30; i++)
		for (int j = 1; j <= 30; j++)
			dp[i][j] = -1;
	for (int i = 1; i <= 30; i++)
		dp[i][i] = dp[i][0] = 1;
	for (int i = 1; i <= 30; i++)
		for (int j = 1; j <= 30; j++)
			if (dp[i][j] == -1)
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];

	while (t--)
	{
		cin >> n >> m;
		cout << dp[m][n] << '\n';
	}
}
