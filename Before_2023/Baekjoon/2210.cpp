#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int N = 5;
vector<vector<int> > board(N, vector<int>(N, 0));
set<int> ans;
int dir[4][2] =
{
	{1,0},{0,1},{-1,0},{0,-1}
};
bool isValid(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < N;
}
void dfs(int x, int y, int cur, int num)
{
	if (cur == 6)
		ans.insert(num);
	else
	{
		for (int i = 0; i < 4; i++)
		{
			int dy = y + dir[i][0], dx = x + dir[i][1];
			if (isValid(dx, dy))
				dfs(dx, dy, cur + 1, num * 10 + board[dy][dx]);
		}
	}
}
int main(void)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			dfs(x, y, 1, board[y][x]);

	cout << ans.size();
}