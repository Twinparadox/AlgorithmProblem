/*
이것이 코테다
DP - 개미 전사
dp[i] = max(dp[i-1], dp[i-2]*2)
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	const int MOD = 796796;
	int N;
	vector<int> dp;

	cin >> N;
	dp.resize(N + 1, 0);

	dp[0] = dp[1] = 1;
	for (int i = 2; i <= N; i++)
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % MOD;

	cout << dp[N];
}