/* [G5] 9252 - LCS2 */
/*
LCS(Longest Common Subsequence)
먼저 DP 테이블을 구하고서, 구한 DP 테이블에서 역으로 답을 구해가는 방식으로 구현
대각선으로 값이 갱신될 때만, 동일한 문자열임을 이용
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
	string str1, str2, ans = "";
	vector<vector<int> > dp;
	int len1, len2;

	cin >> str1 >> str2;
	len1 = str1.length();
	len2 = str2.length();

	dp.resize(len1 + 1, vector<int>(len2 + 1, 0));
	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else if (dp[i - 1][j] < dp[i][j - 1])
				dp[i][j] = dp[i][j - 1];
			else if (dp[i - 1][j] >= dp[i][j - 1])
				dp[i][j] = dp[i - 1][j];
		}
	}

	while (len1 >= 1 && len2 >= 1)
	{
		if (dp[len1][len2] == dp[len1 - 1][len2])
			len1--;
		else if (dp[len1][len2] == dp[len1][len2 - 1])
			len2--;
		else
			ans = str1[len1 - 1] + ans, len1--, len2--;
	}

	int len = ans.length();
	cout << len << '\n';
	for (int i = 0; i < len; i++)
		cout << ans[i];
}