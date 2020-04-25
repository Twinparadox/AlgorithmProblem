#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int dir[4][2] =
{
	{1,0},{-1,0},{0,1},{0,-1}
};
int R, C, ans = 2501;
int sx, sy, ex, ey;
vector<vector<int> > board;
vector<vector<int> > cnt;
vector<vector<int> > sink;
bool isValid(int x, int y)
{
	return y >= 0 && y < R && x >= 0 && x < C;
}
void bfs(int y, int x)
{
	queue<pair<int, int> > q;
	q.push(make_pair(y, x));
	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dir[i][0];
			int ny = cy + dir[i][1];
			if (isValid(nx, ny))
			{
				if (cnt[ny][nx] == 0 && (board[ny][nx] == 0 || board[ny][nx] == 3))
				{
					if (sink[ny][nx] == 0)
					{
						cnt[ny][nx] = cnt[cy][cx] + 1;
						q.push(make_pair(ny, nx));
					}
					else if (sink[ny][nx] > cnt[cy][cx] + 1)
					{
						cnt[ny][nx] = cnt[cy][cx] + 1;
						q.push(make_pair(ny, nx));
					}
				}
			}
		}
	}
}
void water(queue<pair<int, int> >& q)
{
	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dir[i][0], ny = cy + dir[i][1];
			if (isValid(nx, ny))
			{
				if (sink[ny][nx] == 0 && board[ny][nx] == 0)
				{
					sink[ny][nx] = sink[cy][cx] + 1;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	vector<string> arr;
	queue<pair<int, int> > q;
	cin >> R >> C;
	char c;

	arr.resize(R);
	board.resize(R, vector<int>(C, 0));
	sink.resize(R, vector<int>(C, 0));
	cnt.resize(R, vector<int>(C, 0));

	for (int i = 0; i < R; i++)
		cin >> arr[i];

	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			int num = 0;
			switch (arr[y][x])
			{
			case 'D':
				num = 3;
				ey = y, ex = x;
				break;
			case 'S':
				num = 2;
				sy = y, sx = x;
				break;
			case '*':
				num = 1;
				q.push(make_pair(y, x));
				break;
			case '.':
				num = 0;
				break;
			case 'X':
				num = -1;
				break;
			default:
				break;
			}
			board[y][x] = num;
		}
	}

	water(q);

	bfs(sy, sx);

	if (cnt[ey][ex])
		cout << cnt[ey][ex];
	else
		cout << "KAKTUS";
}
