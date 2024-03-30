#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;
int N;
vector<vector<int> > W;
vector<vector<int> > dp;
int TSP(int cur, int visited)
{
	int ret = dp[cur][visited];
	if (ret != 0)
		return ret;

	if (visited == (1 << N) - 1)
	{
		if (W[cur][0] != 0)
			return W[cur][0];
		return INF;
	}

	ret = INF;
	for (int i = 0; i < N; i++)
	{
		if (visited & (1 << i) || W[cur][i] == 0)
			continue;

		int sub = TSP(i, visited | (1 << i)) + W[cur][i];
		ret = ret < sub ? ret : sub;
	}
	dp[cur][visited] = ret;

	return ret;
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N;

	W = vector<vector<int> >(N, vector<int>(N));
	dp = vector<vector<int> >(N, vector<int>(1 << N, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> W[i][j];

	cout << TSP(0, 1);
}