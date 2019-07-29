#include <iostream>
#include <vector>
using namespace std;
bool check(int su)
{
	return su <= 20 && su >= 0;
}
int main(void)
{
	int N;

	cin >> N;
	vector<int> arr(N + 1, 0);
	vector<vector<long long> > dp(N + 1, vector<long long>(21, 0));

	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	dp[1][arr[1]] = 1;
	for (int i = 2; i < N; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			if (dp[i - 1][j] != 0)
			{
				if (check(j + arr[i]))
					dp[i][j + arr[i]] += dp[i - 1][j];
				if (check(j - arr[i]))
					dp[i][j - arr[i]] += dp[i - 1][j];
			}
		}
	}

	cout << dp[N - 1][arr[N]];
}