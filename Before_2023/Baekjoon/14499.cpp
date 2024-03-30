/*
[G5] 14499 - 주사위 굴리기
주사위 굴리는 것에 따라 동서남북, 상하가 바뀌는 걸 처리
구현 & 시뮬레이션 문제
*/
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	vector<vector<int> > board;
	int N, M, cx, cy, K, tmp;
	int dice[6] = { 0, };
	int top = 0, east = 1, south = 2, west = 3, north = 4, bottom = 5;

	cin >> N >> M >> cx >> cy >> K;

	board.resize(N, vector<int>(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	for (int i = 0; i < K; i++)
	{
		int op, nx, ny;
		cin >> op;
		if (op == 1)
		{
			nx = cx, ny = cy + 1;
			if (ny >= M)
				continue;

			if (board[nx][ny] == 0)
				board[nx][ny] = dice[east];
			else
			{
				dice[east] = board[nx][ny];
				board[nx][ny] = 0;
			}
			tmp = east;
			east = top;
			top = west;
			west = bottom;
			bottom = tmp;
			cx = nx, cy = ny;
			cout << dice[top] << '\n';
		}
		else if (op == 2)
		{
			nx = cx, ny = cy - 1;
			if (ny < 0)
				continue;

			if (board[nx][ny] == 0)
				board[nx][ny] = dice[west];
			else
			{
				dice[west] = board[nx][ny];
				board[nx][ny] = 0;
			}
			tmp = west;
			west = top;
			top = east;
			east = bottom;
			bottom = tmp;
			cx = nx, cy = ny;

			cout << dice[top] << '\n';
		}
		else if (op == 3)
		{
			nx = cx - 1, ny = cy;
			if (nx < 0)
				continue;

			if (board[nx][ny] == 0)
				board[nx][ny] = dice[north];
			else
			{
				dice[north] = board[nx][ny];
				board[nx][ny] = 0;
			}
			tmp = north;
			north = top;
			top = south;
			south = bottom;
			bottom = tmp;
			cx = nx, cy = ny;

			cout << dice[top] << '\n';
		}
		else
		{
			nx = cx + 1, ny = cy;
			if (nx >= N)
				continue;

			if (board[nx][ny] == 0)
				board[nx][ny] = dice[south];
			else
			{
				dice[south] = board[nx][ny];
				board[nx][ny] = 0;
			}
			tmp = south;
			south = top;
			top = north;
			north = bottom;
			bottom = tmp;
			cx = nx, cy = ny;

			cout << dice[top] << '\n';
		}
	}
}