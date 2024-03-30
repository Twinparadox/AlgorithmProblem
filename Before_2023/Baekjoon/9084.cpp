#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		vector<int> arr;
		vector<int> dp;

		cin >> N;
		arr.resize(N + 1);
		for (int i = 1; i <= N; i++)
			cin >> arr[i];
		cin >> M;
		dp.resize(M + 1, 0);
		dp[0] = 1;

		for (int i = 1; i <= N; i++)
			for (int j = arr[i]; j <= M; j++)
				dp[j] += dp[j - arr[i]];

		cout << dp[M] << '\n';
	}
}