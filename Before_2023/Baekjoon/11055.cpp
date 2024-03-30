#include <iostream>
using namespace std;
int main(void)
{
	int max, n, arr[1001] = { 0, }, dp[1001] = { 0, };
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		dp[i] = arr[i];
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i; j++)
			if (arr[j] < arr[i])
				dp[i] = dp[i] < (dp[j] + arr[i]) ? (dp[j] + arr[i]) : dp[i];
	max = -1;
	for (int i = 1; i <= n; i++)
		if (max < dp[i])
			max = dp[i];
	cout << max;
}
