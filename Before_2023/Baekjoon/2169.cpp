#include <iostream>
#include <vector>
using namespace std;
int N, M;
const int init = -1e7;
vector<vector<vector<int> > > dp;
vector<vector<int> > arr;
vector<vector<bool> > check;
int dir[3][2] =
{
	{1,0}, {-1,0}, {0,1}
};
bool isValid(int x, int y)
{
	return x >= 0 && x < M && y >= 0 && y < N;
}
int solve(int x, int y, int d)
{
	if (x == M - 1 && y == N - 1)
		return arr[y][x];
	if (dp[d][y][x] != init)
		return dp[d][y][x];

	check[y][x] = true;

	int sub = init;
	for (int i = 0; i < 3; i++)
	{
		int nx = x + dir[i][0], ny = y + dir[i][1];
		if (isValid(nx, ny) && !check[ny][nx])
		{
			int other = solve(nx, ny, i);
			sub = sub < other ? other : sub;
		}
	}
	check[y][x] = false;
	dp[d][y][x] = arr[y][x] + sub;
	return dp[d][y][x];
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	dp.resize(3);
	for (int i = 0; i < 3; i++)
		dp[i].resize(N, vector<int>(M, init));

	arr.resize(N, vector<int>(M, 0));
	check.resize(N, vector<bool>(M, false));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];

	int ans = solve(0, 0, 0);

	cout << ans;
}