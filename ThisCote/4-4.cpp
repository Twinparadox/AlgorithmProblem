/*
이것이 코테다
구현 - 게임 개발
시뮬레이션 문제
4방향 모두 확인한 걸 체크해주기 위한 변수를 마련해야 함
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int N, M;
int dir[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
vector<vector<int> > board;
vector<vector<bool> > check;
bool isValid(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < M;
}
int main(void)
{
	int dx, dy, cx, cy, di, cnt, rotate = 0;
	cin >> N >> M;
	cin >> cx >> cy >> di;

	board.resize(N, vector<int>(M));
	check.resize(N, vector<bool>(M, false));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	check[cx][cy] = true;
	cnt = 1;
	while (1)
	{
		rotate++;
		di = di < 0 ? 3 : (di - 1);
		dx = cx + dir[di][0], dy = cy + dir[di][1];
		if (isValid(dx, dy) && !board[dx][dy] && !check[dx][dy])
		{
			cx = dx, cy = dy;
			cnt++;
			check[cx][cy] = true;
			rotate = 0;
		}
		else if (rotate == 4)
		{
			dx = cx - dir[di][0], dy = cy - dir[di][1];
			if (isValid(dx, dy) && board[dx][dy])
				break;
			else
			{
				cx = dx, cy = dy;
				rotate = 0;
			}
		}
	}
	cout << cnt;
}