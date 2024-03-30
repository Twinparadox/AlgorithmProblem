#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		int N;

		cin >> N;
		vector<int> arr(N + 1, 0);
		vector<vector<int> > dp(N + 1, vector<int>(N + 1, 0));
		for (int i = 1; i <= N; i++)
			cin >> arr[i];

		for (int i = 1; i <= N; i++)
			arr[i] += arr[i - 1];

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N - i; j++)
			{
				int k = i + j;
				dp[j][k] = INT_MAX;
				for (int L = j; L <= k - 1; L++)
				{
					int tmp = dp[j][L] + dp[L + 1][k];
					if (tmp < dp[j][k])
					{
						dp[j][k] = tmp;
					}
				}
				dp[j][k] += arr[k] - arr[j - 1];
			}
		}

		cout << dp[1][N] << '\n';
	}
}