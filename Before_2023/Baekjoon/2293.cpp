#include <iostream>
using namespace std;
int main(void)
{
	int dp[10001] = { 1, }, c[101], n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> c[i];
	
	for (int i = 0; i < n; i++)
		for (int j = c[i]; j <= k; j++)
			dp[j] += dp[j - c[i]];
	cout << dp[k];
}
