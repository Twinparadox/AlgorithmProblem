/*
[S1] ����2
��ǥ���� DP
���� ���� ������ �����Ƿ�, 1���� ���̺�� �ذ� ����
�� ���̺��� �ش� �׼��� ���� �ּ����� ���� ��
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int INF = 2e9;
int main(void)
{
	vector<int> dp(1e5, INF);
	vector<int> coin;
	int n, k;
	cin >> n >> k;

	coin.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> coin[i];
		dp[coin[i]] = 1;
	}

	dp[0] = 0;
	for (int i = 1; i <= k; i++)
		for (int j = 0; j < n; j++)
			if (i - coin[j] >= 0)
				dp[i] = min(dp[i], dp[i - coin[j]] + 1);

	if (dp[k] == INF)
		cout << -1;
	else
		cout << dp[k];
}