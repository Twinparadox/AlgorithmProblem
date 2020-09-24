/*
이것이 코테다
DFS/BFS - 음료수 얼려 먹기
아주 흔한 DFS/BFS 문제
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
vector<string> board;
vector<vector<bool> > check;
int N, M;
bool isValid(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < M;
}
void dfs(int x, int y)
{
	check[x][y] = true;
	int dx, dy;
	for (int i = 0; i < 4; i++)
	{
		dx = x + dir[i][0], dy = y + dir[i][1];
		if (isValid(dx, dy) && board[dx][dy] == '0' && !check[dx][dy])
			dfs(dx, dy);
	}
}
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int ans = 0;

	cin >> N >> M;

	board.resize(N);
	for (int i = 0; i < N; i++)
		cin >> board[i];
	check.resize(N, vector<bool>(M, false));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == '0' && !check[i][j])
			{
				dfs(i, j);
				ans++;
			}
		}
	}

	cout << ans;
}