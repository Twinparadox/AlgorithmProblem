#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int> > board;
int N, res;
int dir[3][2] =
{
	{1,0},{0,1},{1,1}
};
bool isValid(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < N;
}
void bfs()
{
	queue<pair<pair<int, int>, int> > q;
	q.push(make_pair(make_pair(0, 1), 0));
	while (!q.empty())
	{
		int y = q.front().first.first, x = q.front().first.second;
		int hole = q.front().second;
		q.pop();

		if (x == N - 1 && y == N - 1)
		{
			res++;
			continue;
		}

		int nx, ny, cx1, cy1, cx2, cy2;
		switch (hole)
		{
		case 0:
		case 1:
			nx = x + dir[hole][0], ny = y + dir[hole][1];
			cx1 = x + dir[2][0], cy1 = y + dir[2][1];
			if (isValid(nx, ny) && !board[ny][nx])
				q.push(make_pair(make_pair(ny, nx), hole));
			if (isValid(cx1, cy1) && !board[cy1][cx1] && !board[y + 1][x] && !board[y][x + 1])
				q.push(make_pair(make_pair(cy1, cx1), 2));
			break;
		case 2:
			nx = x + dir[hole][0], ny = y + dir[hole][1];
			cx1 = x + dir[0][0], cy1 = y + dir[0][1];
			cx2 = x + dir[1][0], cy2 = y + dir[1][1];
			if (isValid(nx, ny) && !board[ny][nx] && !board[y + 1][x] && !board[y][x + 1])
				q.push(make_pair(make_pair(ny, nx), hole));
			if (isValid(cx1, cy1) && !board[cy1][cx1])
				q.push(make_pair(make_pair(cy1, cx1), 0));
			if (isValid(cx2, cy2) && !board[cy2][cx2])
				q.push(make_pair(make_pair(cy2, cx2), 1));
			break;
		default:
			break;
		}
	}
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N;

	board.resize(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	bfs();
	cout << res;
}