#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int N, M, ans = 0;
vector<vector<int> > island;
vector<vector<int> > check;
int dir[4][2] =
{
	{1,0},
	{-1,0},
	{0,1},
	{0,-1}
};
bool isValid(int x, int y)
{
	return x >= 0 && x < M && y >= 0 && y < N;
}
int bfs(int x, int y)
{
	queue<pair<int, int> > q;
	int result = 0;
	q.push(make_pair(x, y));
	check[y][x] = 1;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dir[i][0], ny = y + dir[i][1];

			result = result < check[y][x] ? check[y][x] : result;
			if (isValid(nx, ny) && island[ny][nx] && !check[ny][nx])
			{
				q.push(make_pair(nx, ny));
				check[ny][nx] = check[y][x] + 1;
			}
		}
	}
	return result - 1;
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	vector<string> arr(N);
	island = vector<vector<int> >(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (arr[i][j] == 'L')
				island[i][j] = 1;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (island[i][j])
			{
				check = vector<vector<int> >(N, vector<int>(M, 0));
				int tmp = bfs(j, i);
				ans = ans < tmp ? tmp : ans;
			}
		}
	}
	cout << ans;
}