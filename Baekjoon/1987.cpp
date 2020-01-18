#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
int dir[4][2] = {
	{1,0}, {-1,0}, {0,1}, {0,-1}
};
int R, C, ans = 0;
vector<bool> isVisit(26, false);
vector<vector<int> > board;
bool isValid(int x, int y)
{
	return x >= 0 && x < C && y >= 0 && y < R;
}
void dfs(int x, int y, int cnt)
{
	isVisit[board[y][x]] = true;
	ans = ans < cnt ? cnt : ans;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dir[i][0], ny = y + dir[i][1];
		if (isValid(nx, ny) && !isVisit[board[ny][nx]])
		{
			dfs(nx, ny, cnt + 1);
		}
	}

	cnt--;
	isVisit[board[y][x]] = false;
}
int main(void)
{
	cin >> R >> C;
	vector<string> arr(R);
	board = vector<vector<int> >(R, vector<int>(C, 0));

	for (int i = 0; i < R; i++)
	{
		cin >> arr[i];
		for (int j = 0; j < C; j++)
			board[i][j] = arr[i][j] - 'A';
	}

	dfs(0, 0, 1);
	cout << ans;
}