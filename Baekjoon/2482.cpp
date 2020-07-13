/*
[G5] 색상환
2차원 DP 문제
*/
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	const int MOD = 1e9 + 3;
	int N, K, ans;
	vector<vector<int> > dp;

	cin >> N >> K;
	dp.resize(N + 1, vector<int>(K + 1, 0));
	for (int i = 0; i <= N; i++)
		dp[i][1] = i, dp[i][0] = 1;

	for (int i = 2; i <= N; i++)
		for (int j = 2; j <= K; j++)
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;

	ans = (dp[N - 1][K] + dp[N - 3][K - 1]) % MOD;
	cout << ans;
}