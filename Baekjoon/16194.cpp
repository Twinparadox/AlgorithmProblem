#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int N;
	cin >> N;
	vector<int> pack(N + 1, 0);
	vector<int> dp(N + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		cin >> pack[i];
		dp[i] = pack[i];
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			int tmp1 = dp[j] + dp[i - j];
			int tmp2 = dp[i];
			dp[i] = tmp1 < tmp2 ? tmp1 : tmp2;
		}
	}
	cout << dp[N];
}