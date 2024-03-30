/*
[G5] 공통 부분 문자열
대표적인 DP
dp[i][j]는 첫번째 문장의 i번째까지의 문자와 두번째 문장의 j번째까지의 문자에 왔을 때,
공통 부분 문자열을 나타내는 것으로 dp를 계속 만들어나가면서 정답 탐색
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
	vector<vector<int> > dp;
	string a, b;
	int alen, blen;

	cin >> a >> b;
	alen = a.length();
	blen = b.length();

	dp.resize(alen + 1, vector<int>(blen + 1, 0));

	int ans = 0;
	for (int i = 1; i <= alen; i++)
	{
		for (int j = 1; j <= blen; j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				ans = ans < dp[i][j] ? dp[i][j] : ans;
			}
		}
	}
	cout << ans;
}