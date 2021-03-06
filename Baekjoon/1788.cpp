#include <iostream>
using namespace std;
long long dp[1000001] = { 0, 1, };
int main(void)
{
	int n, k;
	cin >> n;
	if (n < 0)
		k = -n;
	else
		k = n;
	for (int i = 2; i <= k; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000000;
	if (n > 0)
		cout << 1 << '\n' << dp[k] % 1000000000;
	else if (n == 0)
		cout << "0\n0";
	else
	{
		if ((-n) % 2 == 0)
			cout << -1 << '\n' << dp[k] % 1000000000;
		else
			cout << 1 << '\n' << dp[k] % 1000000000;
	}
	cout << '\n';
}
