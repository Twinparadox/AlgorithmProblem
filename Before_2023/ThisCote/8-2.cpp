/*
이것이 코테다
DP - 1로 만들기
기초 문제
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int N, dp[30001] = { 0, };
	cin >> N;

	for (int i = 2; i <= N; i++)
	{
		dp[i] = dp[i - 1] + 1;

		if (i % 2 == 0)
			dp[i] = min(dp[i / 2] + 1, dp[i]);
		if (i % 3 == 0)
			dp[i] = min(dp[i / 3] + 1, dp[i]);
		if (i % 5 == 0)
			dp[i] = min(dp[i / 5] + 1, dp[i]);
	}

	cout << dp[N];
}