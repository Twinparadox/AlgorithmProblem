#include <iostream>
using namespace std;
int main()
{
	long long dp[36] = { 1, };
	int n;
	cin >> n;
	for (int i = 1; i <= 35; i++)
		for (int j = 0; j < i; j++)
			dp[i] += dp[i - j - 1] * dp[j];
	cout << dp[n];
}
