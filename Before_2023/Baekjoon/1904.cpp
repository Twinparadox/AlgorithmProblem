#include <iostream>
using namespace std;
long long dp[1000001] = { 1, 1, };
int main()
{
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}
	cout << dp[n];
}
