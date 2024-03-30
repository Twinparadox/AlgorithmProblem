#include <iostream>
#include <math.h>
#include <queue>
#include <vector>
using namespace std;
int N, L, R, ans = 0;
vector<vector<int> > board;
vector<vector<int> > buffer;
vector<pair<int, int> > share;
vector<vector<bool> > check;
int dir[4][2] =
{
	{1,0},{-1,0},{0,1},{0,-1}
};
bool isValid(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < N;
}
void dfs(int y, int x)
{
	share.push_back(make_pair(y, x));
	check[y][x] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dir[i][0], ny = y + dir[i][1];
		if (isValid(nx, ny) && !check[ny][nx])
		{
			int sub = abs(board[y][x] - board[ny][nx]);
			if (sub >= L && sub <= R)
				dfs(ny, nx);
		}
	}
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> L >> R;
	board.resize(N, vector<int>(N));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	bool flag = true;
	while (flag)
	{
		flag = false;
		buffer = board;
		check = vector<vector<bool> >(N, vector<bool>(N, false));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!check[i][j])
				{
					dfs(i, j);
					if (share.size() == 1)
						share.clear();
					else
					{
						flag = true;
						int size = share.size(), sum = 0;
						for (int i = 0; i < size; i++)
							sum += buffer[share[i].first][share[i].second];

						for (int i = 0; i < size; i++)
							buffer[share[i].first][share[i].second] = sum / size;

						share.clear();
					}
				}
			}
		}

		board = buffer;

		if (flag)
			ans++;
	}
	cout << ans;
}