#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > board;
int dir[8][2] =
{
{1,0},{0,1},{-1,0},{0,-1},
{1,1},{-1,1},{1,-1},{-1,-1}
};
int M, N;
bool isValid(const int dy, const int dx)
{
	return dy >= 0 && dy < M && dx >= 0 && dx < N;
}
void dfs(int y, int x)
{
	board[y][x] = -1;
	for (int i = 0; i < 8; i++)
	{
		int dy = y + dir[i][0], dx = x + dir[i][1];
		if (isValid(dy, dx) && board[dy][dx] == 1)
			dfs(dy, dx);
	}
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int cnt = 0;
	cin >> M >> N;
	board = vector<vector<int > >(M, vector<int>(N, 0));

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	for (int y = 0; y < M; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (board[y][x] == 1)
			{
				dfs(y, x);
				cnt++;
			}
		}
	}
	cout << cnt;
}