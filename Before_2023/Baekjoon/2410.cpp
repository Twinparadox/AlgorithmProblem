/* [S1] 2410 - 2의 멱수의 합 */
/*
2차원 DP로 해결 가능
dp[k][i]는 2^0 ~ 2^k까지의 수로 i번째 수를 만들 수 있는 경우의 수를 의미
부분 최적해를 바탕으로 최종 결과를 도출해낼 수 있음
dp[0][0~N]은 1로 초기화하고, dp[0~k][0]도 1로 초기화하여 사용
*/
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int main(void)
{
	const int MOD = 1e9;
	int N, k, maxK;
	vector<vector<int> > dp;

	cin >> N;
	maxK = (int)log2(N);
	dp.resize(maxK + 1, vector<int>(N + 1, 0));
	for (int i = 1; i <= N; i++)
		dp[0][i] = 1;
	for (int k = 1; k <= maxK; k++)
	{
		dp[k][0] = 1;
		int cur = pow(2, k);
		for (int i = 1; i < cur; i++)
			dp[k][i] = dp[k - 1][i];
		for (int i = cur; i <= N; i++)
			dp[k][i] = (dp[k - 1][i] + dp[k][i - cur]) % MOD;
	}
	cout << dp[maxK][N];
}