#include <iostream>
using namespace std;
int main(void)
{
	int n;
	long long dp[21] = { 0,1 };
	cin >> n;
	for (int i = 2; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	cout << dp[n];
}
