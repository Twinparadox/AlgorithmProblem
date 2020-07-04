/*
[G5] 벼락치기
0-1 Knapsack 문제
dp[k]는 k일 때의 최대 점수
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int N, T, ti, sc;
	vector<int> dp;

	cin >> N >> T;
	dp.resize(T + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		cin >> ti >> sc;
		for (int j = T; j >= ti; j--)
			dp[j] = max(dp[j], dp[j - ti] + sc);
	}
	cout << dp[T];
}