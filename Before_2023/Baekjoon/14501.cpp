#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	pair<int, int> arr[16] = { {0,0}, };
	int dp[16] = { 0, }, n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;

	for (int i = 0; i < n; i++)
	{
		if (dp[i] > dp[i + 1])
			dp[i + 1] = dp[i];
		if (dp[i + arr[i].first] < dp[i] + arr[i].second)
			dp[i + arr[i].first] = dp[i] + arr[i].second;
	}
	cout << dp[n];
}
