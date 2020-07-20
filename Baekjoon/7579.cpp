/*
[G5] 7579 - ��
2���� DP ����
dp[i][j] = i��°������ �ۿ��� j ������� ��� �ִ� �޸�
���� ���ǿ��� �����ؾ� �ϴ� ����, ���� �ϴ� �޸𸮰� M �̻��� ��
����, �� �̻��� �޸𸮿��� �� ���� ����� �ִٸ�, �װ��� ������
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	const int INF = 2e9, CMAX = 1e4;
	int N, M, ans = INF;
	vector<int> memory, cost;
	vector<vector<int> > dp;

	cin >> N >> M;
	memory.resize(N + 1);
	cost.resize(N + 1);
	dp.resize(N + 1, vector<int>(CMAX + 1, 0));

	for (int i = 1; i <= N; i++)
		cin >> memory[i];
	for (int i = 1; i <= N; i++)
		cin >> cost[i];


	dp[1][cost[1]] = memory[1];
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= CMAX; j++)
		{
			if (j - cost[i] >= 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + memory[i]);

			dp[i][j] = max(dp[i][j], dp[i - 1][j]);

			if (dp[i][j] >= M)
				ans = min(ans, j);
		}
	}

	cout << ans;
}