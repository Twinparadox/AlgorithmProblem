/*
[G4] 2096 - ��������
2���� DP ����
dp[i][j] = i��°������ �ٿ��� jĭ������ �ִ� ����, �ּ� ����
�ٸ�, �� �ڵ忡���� dp ���̺��� 2�������� ������ �ʰ�,
1�������� �ΰ� �ܰ踶�� �����ϵ��� ��
min, max 2���� ���̺� ����
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	vector<int> dp1(3, 0), dp2(3, 0), tmp(3);
	int N, first, second, third;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> first >> second >> third;

		tmp[0] = max(dp1[0] + first, dp1[1] + first);
		tmp[1] = max(dp1[0] + second, max(dp1[1] + second, dp1[2] + second));
		tmp[2] = max(dp1[1] + third, dp1[2] + third);
		dp1.assign(tmp.begin(), tmp.end());

		tmp[0] = min(dp2[0] + first, dp2[1] + first);
		tmp[1] = min(dp2[0] + second, min(dp2[1] + second, dp2[2] + second));
		tmp[2] = min(dp2[1] + third, dp2[2] + third);
		dp2.assign(tmp.begin(), tmp.end());
	}

	int ans1 = -1, ans2 = 1e7;
	for (int i = 0; i < 3; i++)
	{
		ans1 = max(ans1, dp1[i]);
		ans2 = min(ans2, dp2[i]);
	}
	cout << ans1 << ' ' << ans2;
}