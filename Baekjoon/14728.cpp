/*
[G5] ����ġ��
0-1 Knapsack ����
dp[k]�� k�� ���� �ִ� ����
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int N, T, ti, sc;
	vector<int> dp;

	cin >> N >> T;
	dp.resize(T + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		cin >> ti >> sc;
		for (int j = T; j >= ti; j--)
			dp[j] = max(dp[j], dp[j - ti] + sc);
	}
	cout << dp[T];
}