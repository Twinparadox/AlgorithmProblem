/*
[G4] 2616 - 소형 기관차
DP 문제
dp[i][k] = i대의 기관차가 k번째 객차까지 운송할 수 있는 최대 손님 수(부분최적해)
dp[3][N]이 최종 결과가 되는 셈
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int N, maxC;
	vector<int> arr, sum;
	vector<vector<int> > dp;

	cin >> N;

	arr.resize(N + 1);
	sum.resize(N + 1, 0);
	dp.resize(4, vector<int>(N + 1, 0));
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}

	cin >> maxC;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = i * maxC; j <= N; j++)
		{
			int sub = sum[j] - sum[j - maxC];
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - maxC] + sub);
		}
	}
	cout << dp[3][N];
}