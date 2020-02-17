#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	long long N, K, M;
	cin >> N >> K >> M;

	vector<vector<int> > binomial(2001, vector<int>(2001, 0));
	for (int i = 0; i < M; i++)
	{
		binomial[i][0] = 1;
		for (int j = 1; j <= i; j++)
			binomial[i][j] = (binomial[i - 1][j - 1] + binomial[i - 1][j]) % M;
	}

	int ans = 1;
	while (N || K)
	{
		ans *= binomial[N % M][K % M];
		N /= M;
		K /= M;
		ans %= M;
	}
	cout << ans;
}