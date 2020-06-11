/* [G5] 2240 - 자두나무 */
/*
3차원 DP 문제
첫번째 차원에서는 1, 2에 대한 각각의 최적해를 담음
두번째 차원은 특정 시점 T에 대한 최적해
세번째 차원은 이동 횟수에 따른 최적해

최종적으로 왼쪽에 있을 떄와 오른 쪽에 있을 때,
그리고 그때의 이동 횟수에 따른 결과 중 최대가 되는 값이 문제의 최적해가 됨
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