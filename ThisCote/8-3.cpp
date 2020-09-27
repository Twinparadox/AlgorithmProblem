/*
이것이 코테다
DP - 개미 전사
dp[i] = max(dp[i-1], dp[i-2]+arr[i])
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int N;
	vector<int> arr, dp;

	cin >> N;
	arr.resize(N + 1);
	dp.resize(N + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		dp[i] = arr[i];
	}

	for (int i = 2; i <= N; i++)
		dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);

	cout << dp[N];
}