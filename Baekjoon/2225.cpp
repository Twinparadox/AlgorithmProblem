#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int N, K, mod = 1000000000;
	cin >> N >> K;
	vector<vector<long long> > dp(201, vector<long long>(201, 0));

	for (int i = 0; i <= N; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= K; i++)
		for (int j = 0; j <= N; j++)
			for (int l = 0; l <= j; l++)
				dp[i][j] = (dp[i][j] + dp[i - 1][l]) % mod;

	cout << dp[K][N];
}
