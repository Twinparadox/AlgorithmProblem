/*
[S1] 동전2
대표적인 DP
동전 수에 제한이 없으므로, 1차원 테이블로 해결 가능
각 테이블은 해당 액수를 위한 최소한의 동전 수
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int INF = 2e9;
int main(void)
{
	vector<int> dp(1e5, INF);
	vector<int> coin;
	int n, k;
	cin >> n >> k;

	coin.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> coin[i];
		dp[coin[i]] = 1;
	}

	dp[0] = 0;
	for (int i = 1; i <= k; i++)
		for (int j = 0; j < n; j++)
			if (i - coin[j] >= 0)
				dp[i] = min(dp[i], dp[i - coin[j]] + 1);

	if (dp[k] == INF)
		cout << -1;
	else
		cout << dp[k];
}