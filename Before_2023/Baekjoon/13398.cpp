/* [G5] 13398 - 연속합2 */
/*
연속합 문제
DP로 문제를 풀 수 있고, 1차원 DP Table 2개를 작성해 풀어냄
dp1[K]은 첫번째부터 K번째 숫자까지의 연속합(숫자 빼기 X)
dp2[K]은 N번째부터 K번째 숫자까지의 연속합(숫자 빼기 X)

이렇게 구해서, 그냥 연속합을 구했을 때와 dp1[K-1] + dp2[K+1]의 합 중 최적해 탐색
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	vector<int> arr, dp1, dp2;
	int N, ans = -1e9;

	cin >> N;
	arr.resize(N + 1, 0);
	dp1.resize(N + 1, 0);
	dp2.resize(N + 1, 0);
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	dp1[1] = arr[1];
	for (int i = 2; i <= N; i++)
	{
		dp1[i] = arr[i];
		if (dp1[i] < dp1[i - 1] + arr[i])
			dp1[i] = dp1[i - 1] + arr[i];
	}

	dp2[N] = arr[N];
	for (int i = N - 1; i >= 1; i--)
	{
		dp2[i] = arr[i];
		if (dp2[i] < dp2[i + 1] + arr[i])
			dp2[i] = dp2[i + 1] + arr[i];
	}

	for (int i = 1; i <= N; i++)
		ans = ans < dp1[i] ? dp1[i] : ans;
	for (int i = 1; i <= N - 1; i++)
		ans = max(ans, dp1[i - 1] + dp2[i + 1]);

	cout << ans;
}