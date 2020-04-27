#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace  std;
int dir[4][2] =
{
	{1,0},{-1,0},{0,1},{0,-1}
};
const int R = 12, C = 6;

vector<vector<bool> > check;
vector<string> board;
vector<string> tmp;

bool isValid(int x, int y)
{
	return x >= 0 && x < C && y >= 0 && y < R;
}
void releaseBoard()
{
	for (int x = 0; x < C; x++)
	{
		queue<char> q;
		bool flag = false;
		int cnt = 0;
		for (int y = 0; y < R; y++)
		{
			if (tmp[y][x] != '.')
			{
				flag = true;
				q.push(tmp[y][x]);
			}
			if (flag && tmp[y][x] == '.')
				cnt++;
		}
		if (cnt)
		{
			int size = q.size();
			for (int y = 0; y < R - size; y++)
				tmp[y][x] = '.';
			for (int y = R - size; y < R; y++)
			{
				tmp[y][x] = q.front();
				q.pop();
			}
		}
	}
}
bool find(int y, int x)
{
	int cnt = 0;
	queue<pair<int, int> > q;
	vector<pair<int, int> > v;
	q.push(make_pair(y, x));
	check[y][x] = true;

	while (!q.empty())
	{
		int cy = q.front().first, cx = q.front().second;
		q.pop();
		cnt++;
		v.push_back(make_pair(cy, cx));

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dir[i][0], nx = cx + dir[i][1];
			if (isValid(nx, ny) && !check[ny][nx] && board[cy][cx] == board[ny][nx])
			{
				check[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}
	}

	if (cnt >= 4)
	{
		for (int i = 0; i < cnt; i++)
			tmp[v[i].first][v[i].second] = '.';
		releaseBoard();
		return true;
	}
	else
		return false;
}
int main(void)
{
	int ans = 0;

	board.resize(R);

	for (int i = 0; i < R; i++)
		cin >> board[i];

	tmp = board;
	while (1)
	{
		check = vector<vector<bool> >(R, vector<bool>(C, false));
		int combo = 0;
		for (int y = 0; y < R; y++)
		{
			for (int x = 0; x < C; x++)
			{
				if (board[y][x] != '.' && !check[y][x])
				{
					bool broken = find(y, x);
					if (broken)
						combo++;
				}
			}
		}

		if (!combo)
			break;
		else
			ans++;

		board = tmp;
	}

	cout << ans;
}