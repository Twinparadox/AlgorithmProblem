#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int N;
	cin >> N;
	vector<int> dp(N + 1, 0);

	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= N; i++)
		dp[i] = dp[i - 1] + dp[i - 2] * 2;

	int ans = 0;
	if (N % 2 == 0)
		ans = (dp[N] + dp[N / 2] + 2 * dp[(N - 1) / 2]) / 2;
	else
		ans = (dp[N] + dp[N / 2]) / 2;
	cout << ans;
}