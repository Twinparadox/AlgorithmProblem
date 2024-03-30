#include <iostream>
#include <vector>
using namespace std;
int dir[8][2] = {
{1,0},
{0,1},
{-1,0},
{0,-1},
{1,1},
{1,-1},
{-1,1},
{-1,-1}
};
int island, w, h;
vector<vector<int> > board;
vector<vector<bool> > visit;
void dfs(int y, int x)
{
	visit[y][x] = true;

	for (int i = 0; i < 8; i++)
	{
		int ny = y + dir[i][0], nx = x + dir[i][1];

		if (((ny >= 0 && ny < h) && (nx >= 0 && nx < w))
			&& (visit[ny][nx] == false && board[ny][nx] == 1))
			dfs(ny, nx);
	}
}
int main(void)
{
	while (1)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;

		island = 0;
		board = vector<vector<int> >(h, vector<int>(w));
		visit = vector<vector<bool> >(h, vector<bool>(w, false));
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> board[i][j];

		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				if (board[y][x] == 1 && visit[y][x] == false)
				{
					dfs(y, x);
					island++;
				}
			}
		}

		cout << island << '\n';
	}
}