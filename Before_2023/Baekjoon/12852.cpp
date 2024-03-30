#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
int N;
vector<int> dp;
vector<int> output;
int solve(int k)
{
	int ans = INT_MAX;
	int tmp, out;

	if (dp[k] != -1)
		return dp[k];

	if (k % 3 == 0)
	{
		tmp = solve(k / 3);
		if (tmp < ans)
		{
			out = k / 3;
			ans = tmp;
		}
	}
	if (k % 2 == 0)
	{
		tmp = solve(k / 2);
		if (tmp < ans)
		{
			out = k / 2;
			ans = tmp;
		}
	}

	tmp = solve(k - 1);
	if (tmp < ans)
	{
		out = k - 1;
		ans = tmp;
	}

	output[k] = out;
	return dp[k] = ans + 1;
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	dp = vector<int>(N + 1, -1);
	output = vector<int>(N + 1, -1);
	dp[0] = dp[1] = 0;

	cout << solve(N) << '\n';

	int size = output.size();
	cout << N << ' ';

	int idx = N;
	while (output[idx] != -1)
	{
		cout << output[idx] << ' ';
		idx = output[idx];
	}
}