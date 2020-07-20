/*
[G5] 7579 - 앱
2차원 DP 문제
dp[i][j] = i번째까지의 앱에서 j 비용으로 얻는 최대 메모리
문제 조건에서 유념해야 하는 것은, 얻어야 하는 메모리가 M 이상인 것
따라서, 그 이상의 메모리에서 더 적은 비용이 있다면, 그것이 최적해
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	const int INF = 2e9, CMAX = 1e4;
	int N, M, ans = INF;
	vector<int> memory, cost;
	vector<vector<int> > dp;

	cin >> N >> M;
	memory.resize(N + 1);
	cost.resize(N + 1);
	dp.resize(N + 1, vector<int>(CMAX + 1, 0));

	for (int i = 1; i <= N; i++)
		cin >> memory[i];
	for (int i = 1; i <= N; i++)
		cin >> cost[i];


	dp[1][cost[1]] = memory[1];
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= CMAX; j++)
		{
			if (j - cost[i] >= 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + memory[i]);

			dp[i][j] = max(dp[i][j], dp[i - 1][j]);

			if (dp[i][j] >= M)
				ans = min(ans, j);
		}
	}

	cout << ans;
}