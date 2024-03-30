/*
[S1] 1926 - 그림
BFS
BFS를 통해서 그림 숫자랑 최대 넓이 구하는 간단한 문제
*/
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
vector<vector<int> > board;
bool isValid(int x, int y)
{
	return x >= 0 && x < M && y >= 0 && y < N;
}
int bfs(int x, int y)
{
	int cnt = 1;
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	board[y][x] = -1;
	while (!q.empty())
	{
		int cx = q.front().first, cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dir[i][0], ny = cy + dir[i][1];
			if (isValid(nx, ny) && board[ny][nx] == 1)
			{
				q.push(make_pair(nx, ny));
				cnt++;
				board[ny][nx] = -1;
			}
		}
	}
	return cnt;
}
int main(void)
{
	int pCnt = 0, pSize = 0;
	cin >> N >> M;
	board.resize(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (board[y][x] == 1)
			{
				pCnt++;
				int sub = bfs(x, y);
				pSize = max(sub, pSize);
			}
		}
	}
	cout << pCnt << '\n' << pSize;
}