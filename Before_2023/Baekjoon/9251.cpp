#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	string a, b;
	int alen, blen;

	cin >> a >> b;
	alen = a.length();
	blen = b.length();
	vector<vector<int> > dp(alen + 1, vector<int>(blen + 1, 0));

	for (int i = 1; i <= alen; i++)
	{
		for (int j = 1; j <= blen; j++)
		{
			if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = dp[i][j - 1] > dp[i - 1][j] ? dp[i][j - 1] : dp[i - 1][j];
		}
	}
	cout << dp[alen][blen];
}