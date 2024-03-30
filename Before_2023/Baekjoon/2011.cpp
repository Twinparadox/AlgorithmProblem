#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
	string str;
	int len;
	const int MOD = 1000000;
	cin >> str;

	len = str.length();
	vector<int> arr(len + 1);
	vector<int> dp(len + 1, 0);

	for (int i = 0; i < len; i++)
		arr[i + 1] = str[i] - '0';

	if (arr[1] == 0)
	{
		cout << 0;
		return 0;
	}
	dp[1] = 1;
	for (int i = 2; i <= len; i++)
	{
		int n = arr[i - 1] * 10 + arr[i];
		if (n == 0)
		{
			cout << 0;
			return 0;
		}
		if (n > 26 || n < 10)
			dp[i] = dp[i - 1];
		else
		{
			if (arr[i] != 0)
				dp[i] += dp[i - 1];
			if (arr[i - 1] != 0)
			{
				if (i <= 2)
					dp[i] += 1;
				else
					dp[i] = (dp[i] + dp[i - 2]) % MOD;
			}
		}
	}
	cout << dp[len];
	return 0;
}