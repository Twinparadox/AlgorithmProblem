/* [S1] 2410 - 2�� ����� �� */
/*
2���� DP�� �ذ� ����
dp[k][i]�� 2^0 ~ 2^k������ ���� i��° ���� ���� �� �ִ� ����� ���� �ǹ�
�κ� �����ظ� �������� ���� ����� �����س� �� ����
dp[0][0~N]�� 1�� �ʱ�ȭ�ϰ�, dp[0~k][0]�� 1�� �ʱ�ȭ�Ͽ� ���
*/
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int main(void)
{
	const int MOD = 1e9;
	int N, k, maxK;
	vector<vector<int> > dp;

	cin >> N;
	maxK = (int)log2(N);
	dp.resize(maxK + 1, vector<int>(N + 1, 0));
	for (int i = 1; i <= N; i++)
		dp[0][i] = 1;
	for (int k = 1; k <= maxK; k++)
	{
		dp[k][0] = 1;
		int cur = pow(2, k);
		for (int i = 1; i < cur; i++)
			dp[k][i] = dp[k - 1][i];
		for (int i = cur; i <= N; i++)
			dp[k][i] = (dp[k - 1][i] + dp[k][i - cur]) % MOD;
	}
	cout << dp[maxK][N];
}