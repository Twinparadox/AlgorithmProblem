#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int N, mod = 1000000000;
	long long dp[101][10] = { 0, }, ans = 0;
	cin >> N;

	for (int i = 1; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= N; i++)
	{
		dp[i][0] = dp[i - 1][1];
		dp[i][9] = dp[i - 1][8];
		for (int j = 1; j < 9; j++)
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
	}
	for (int i = 0; i < 10; i++)
		ans = (ans + dp[N][i]) % mod;
	cout << ans;
}