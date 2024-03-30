/*
[G5] - 15683 감시
그냥 완전한 구현-시뮬레이션 문제
예외 사항이라고는,
1. 벽만 아니면 CCTV도 관통할 수 있다는 점
2. CCTV가 없는 경우도 있는 점
*/
#include <iostream>
#include <vector>
using namespace std;
struct CCTV
{
	int x, y, cate;
};
int N, M, ans, nCCTV;
vector<vector<int> > board;
vector<struct CCTV> cctvArr;
vector<int> dir;
int count(vector<vector<int> >& board)
{
	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (!board[i][j])
				cnt++;
	return cnt;
}
bool isValid(int x, int y)
{
	return x >= 0 && x < M && y >= 0 && y < N;
}
void right(vector<vector<int> >& tmpBoard, int x, int y)
{
	for (int nx = x + 1; nx < M && tmpBoard[y][nx] != 6; nx++)
		tmpBoard[y][nx] = 9;
}
void left(vector<vector<int> >& tmpBoard, int x, int y)
{
	for (int nx = x - 1; nx >= 0 && tmpBoard[y][nx] != 6; nx--)
		tmpBoard[y][nx] = 9;
}
void up(vector<vector<int> >& tmpBoard, int x, int y)
{
	for (int ny = y + 1; ny < N && tmpBoard[ny][x] != 6; ny++)
		tmpBoard[ny][x] = 9;
}
void down(vector<vector<int> >& tmpBoard, int x, int y)
{
	for (int ny = y - 1; ny >= 0 && tmpBoard[ny][x] != 6; ny--)
		tmpBoard[ny][x] = 9;
}
void mapping(vector<vector<int> >& tmpBoard, int idx, int cate, int dir)
{
	if (cate == 1)
	{
		switch (dir)
		{
		case 0:
			right(tmpBoard, cctvArr[idx].x, cctvArr[idx].y);
			break;
		case 1:
			down(tmpBoard, cctvArr[idx].x, cctvArr[idx].y);
			break;
		case 2:
			left(tmpBoard, cctvArr[idx].x, cctvArr[idx].y);
			break;
		case 3:
			up(tmpBoard, cctvArr[idx].x, cctvArr[idx].y);
			break;
		}
	}
	else if (cate == 2)
	{
		switch (dir)
		{
		case 0:
			left(tmpBoard, cctvArr[idx].x, cctvArr[idx].y);
			right(tmpBoard, cctvArr[idx].x, cctvArr[idx].y);
			break;
		case 1:
			up(tmpBoard, cctvArr[idx].x, cctvArr[idx].y);
			down(tmpBoard, cctvArr[idx].x, cctvArr[idx].y);
			break;
		}
	}
	else if (cate == 3)
	{
		switch (dir)
		{
		case 0:
			up(tmpBoard, cctvArr[idx].x, cctvArr[idx].y);
			right(tmpBoard, cctvArr[idx].x, cctvArr[idx].y);
			break;
		case 1:
			down(tmpBoard, cctvArr[idx].x, cctvArr[idx].y);
			right(tmpBoard, cctvArr[idx].x, cctvArr[idx].y);
			break;
		case 2:
			left(tmpBoard, cctvArr[idx].x, cctvArr[idx].y);
			down(tmpBoard, cctvArr[idx].x, cctvArr[idx].y);
			break;
		case 3:
			up(tmpBoard, cctvArr[idx].x, cctvArr[idx].y);
			left(tmpBoard, cctvArr[idx].x, cctvArr[idx].y);
			break;
		}

	}
	else if (cate == 4)
	{
		switch (dir)
		{
		case 0:
			right(tmpBoard, cctvArr[idx].x, cctvArr[idx].y);
			up(tmpBoard, cctvArr[idx].x, cctvArr[idx].y);
			left(tmpBoard, cctvArr[idx].x, cctvArr[idx].y);
			break;
		case 1:
			down(tmpBoard, cctvArr[idx].x, cctvArr[idx].y);
			right(tmpBoard, cctvArr[idx].x, cctvArr[idx].y);
			up(tmpBoard, cctvArr[idx].x, cctvArr[idx].y);
			break;
		case 2:
			left(tmpBoard, cctvArr[idx].x, cctvArr[idx].y);
			down(tmpBoard, cctvArr[idx].x, cctvArr[idx].y);
			right(tmpBoard, cctvArr[idx].x, cctvArr[idx].y);
			break;
		case 3:
			up(tmpBoard, cctvArr[idx].x, cctvArr[idx].y);
			left(tmpBoard, cctvArr[idx].x, cctvArr[idx].y);
			down(tmpBoard, cctvArr[idx].x, cctvArr[idx].y);
			break;
		}
	}
	else if (cate == 5)
	{
		left(tmpBoard, cctvArr[idx].x, cctvArr[idx].y);
		right(tmpBoard, cctvArr[idx].x, cctvArr[idx].y);
		up(tmpBoard, cctvArr[idx].x, cctvArr[idx].y);
		down(tmpBoard, cctvArr[idx].x, cctvArr[idx].y);
	}
}
void check(int cur)
{
	int nDir = 4;
	if (cctvArr[cur].cate == 2)
		nDir = 2;
	else if (cctvArr[cur].cate == 5)
		nDir = 1;
	for (int d = 0; d < nDir; d++)
	{
		dir[cur] = d;
		if (cur == nCCTV - 1)
		{
			vector<vector<int> > tmp;
			tmp.assign(board.begin(), board.end());

			for (int i = 0; i < nCCTV; i++)
				mapping(tmp, i, cctvArr[i].cate, dir[i]);

			int sub = count(tmp);
			ans = ans < sub ? ans : sub;
		}
		else
		{
			check(cur + 1);
		}
	}
}
int main(void)
{
	cin >> N >> M;
	board.resize(N, vector<int>(M));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
			if (board[i][j] >= 1 && board[i][j] <= 5)
				cctvArr.push_back({ j,i,board[i][j] });
		}
	}
	nCCTV = cctvArr.size();
	dir.resize(nCCTV, 0);
	ans = N * M;

	if (nCCTV)
		check(0);
	else
	{
		int sub = count(board);
		ans = sub;
	}

	cout << ans;
}