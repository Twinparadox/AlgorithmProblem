/*
이것이 코테다
DP - 개미 전사
dp[i] = min(dp[i], dp[i-k]+1) or INF
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int N, M;
	vector<int> arr, dp;

	cin >> N >> M;
	arr.resize(N + 1);
	dp.resize(M + 1, M + 1);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	dp[0] = 0;
	for (int i = 0; i < N; i++)
		for (int j = arr[i]; j <= M; j++)
			if (dp[j - arr[i]] != M + 1)
				dp[j] = min(dp[j], dp[j - arr[i]] + 1);

	if (dp[M] == M + 1)
		cout << -1;
	else
		cout << dp[M];
}