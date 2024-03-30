/* [G5] 2240 - �ڵγ��� */
/*
3���� DP ����
ù��° ���������� 1, 2�� ���� ������ �����ظ� ����
�ι�° ������ Ư�� ���� T�� ���� ������
����° ������ �̵� Ƚ���� ���� ������

���������� ���ʿ� ���� ���� ���� �ʿ� ���� ��,
�׸��� �׶��� �̵� Ƚ���� ���� ��� �� �ִ밡 �Ǵ� ���� ������ �����ذ� ��
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int T, W;
	vector<int> arr;
	vector<vector<vector<int> > > dp;
	cin >> T >> W;

	arr.resize(T + 1);
	dp.resize(3, vector<vector<int> >(T + 1, vector<int>(W + 1, 0)));

	for (int i = 1; i <= T; i++)
	{
		cin >> arr[i];
		if (arr[i] == 1)
		{
			dp[1][i][0] = dp[1][i - 1][0] + 1;
			dp[2][i][0] = 0;
		}
		else
		{
			dp[1][i][0] = dp[1][i - 1][0];
			dp[2][i][0] = 0;
		}
	}

	for (int i = 1; i <= T; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			if (arr[i] == 1)
			{
				dp[1][i][j] = max(dp[1][i][j], dp[1][i - 1][j] + 1);
				dp[1][i][j] = max(dp[1][i][j], dp[2][i - 1][j - 1] + 1);

				dp[2][i][j] = max(dp[2][i][j], dp[1][i - 1][j - 1]);
				dp[2][i][j] = max(dp[2][i][j], dp[2][i - 1][j]);
			}
			else
			{
				dp[1][i][j] = max(dp[1][i][j], dp[1][i - 1][j]);
				dp[1][i][j] = max(dp[1][i][j], dp[2][i - 1][j - 1]);

				dp[2][i][j] = max(dp[2][i][j], dp[1][i - 1][j - 1] + 1);
				dp[2][i][j] = max(dp[2][i][j], dp[2][i - 1][j] + 1);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= 2; i++)
		for (int j = 0; j <= W; j++)
			ans = max(ans, dp[i][T][W]);

	cout << ans;
}