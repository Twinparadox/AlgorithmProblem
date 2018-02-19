#include <iostream>
using namespace std;
int main(void)
{
	int n, max, arr[201] = { 0, }, dp[201] = { 0, };
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i; j++)
			if (arr[j] < arr[i])
				dp[i] = dp[i] < (dp[j] + 1) ? (dp[j] + 1) : dp[i];
	max = -1;
	for (int i = 1; i <= n; i++)
		max = max < dp[i] ? dp[i] : max;
	cout << n - max - 1;
}
