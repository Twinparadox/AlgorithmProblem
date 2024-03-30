#include <iostream>
using namespace std;
int main(void)
{
	int arr[1001], n, dp[1001] = { 0, };
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	dp[1] = arr[1];
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (dp[i] < arr[j] + dp[i - j])
				dp[i] = arr[j] + dp[i - j];
		}
	}
	cout << dp[n];
}
