#include <iostream>
#include <vector>
using namespace std;
int N;
vector<bool> col;
vector<bool> cross1;
vector<bool> cross2;
bool isOK(int r, int c)
{
	if (col[c] || cross1[r + c] || cross2[r + N - c])
		return false;
	return true;
}
int dfs(int r)
{
	if (r == N)
		return 1;

	int ans = 0;
	for (int c = 0; c < N; c++)
	{
		if (isOK(r, c))
		{
			col[c] = true;
			cross1[r + c] = true;
			cross2[r + N - c] = true;

			ans += dfs(r + 1);

			col[c] = false;
			cross1[r + c] = false;
			cross2[r + N - c] = false;
		}
	}
	return ans;
}
int main(void)
{
	int res;
	cin >> N;
	col = vector<bool>(N, false);
	cross1 = vector<bool>(N * 2, false);
	cross2 = vector<bool>(N * 2, false);

	res = dfs(0);
	cout << res;
}