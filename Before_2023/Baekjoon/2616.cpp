/*
[G4] 2616 - ���� �����
DP ����
dp[i][k] = i���� ������� k��° �������� ����� �� �ִ� �ִ� �մ� ��(�κ�������)
dp[3][N]�� ���� ����� �Ǵ� ��
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