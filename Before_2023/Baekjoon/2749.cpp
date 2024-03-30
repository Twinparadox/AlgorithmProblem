#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int mod = 1000000;
	int p = mod / 10 * 15;
	vector<int> dp(p);
	long long n;
	cin >> n;

	dp[0] = 0, dp[1] = 1;
	for (int i = 2; i < p; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % mod;

	cout << dp[n%p];
}