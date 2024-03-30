/*
[G5] ���� �κ� ���ڿ�
��ǥ���� DP
dp[i][j]�� ù��° ������ i��°������ ���ڿ� �ι�° ������ j��°������ ���ڿ� ���� ��,
���� �κ� ���ڿ��� ��Ÿ���� ������ dp�� ��� �������鼭 ���� Ž��
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