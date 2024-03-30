#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int ans = 0, N;
vector<vector<int> > board;
void process(int dir)
{
	queue<int> q;
	if (dir == 0)
	{
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if (board[y][x])
					q.push(board[y][x]);
				board[y][x] = 0;
			}

			int idx = 0;
			while (!q.empty())
			{
				int cur = q.front();
				q.pop();

				if (board[y][idx] == 0)
					board[y][idx] = cur;
				else if (board[y][idx] == cur)
				{
					board[y][idx] = cur * 2;
					idx++;
				}
				else
				{
					idx++;
					board[y][idx] = cur;
				}
			}
		}
	}
	else if (dir == 1)
	{
		for (int y = 0; y < N; y++)
		{
			for (int x = N - 1; x >= 0; x--)
			{
				if (board[y][x])
					q.push(board[y][x]);
				board[y][x] = 0;
			}

			int idx = N - 1;
			while (!q.empty())
			{
				int cur = q.front();
				q.pop();

				if (board[y][idx] == 0)
					board[y][idx] = cur;
				else if (board[y][idx] == cur)
				{
					board[y][idx] = cur * 2;
					idx--;
				}
				else
				{
					idx--;
					board[y][idx] = cur;
				}
			}
		}
	}
	else if (dir == 2)
	{
		for (int x = 0; x < N; x++)
		{
			for (int y = 0; y < N; y++)
			{
				if (board[y][x])
					q.push(board[y][x]);
				board[y][x] = 0;
			}

			int idx = 0;
			while (!q.empty())
			{
				int cur = q.front();
				q.pop();

				if (board[idx][x] == 0)
					board[idx][x] = cur;
				else if (board[idx][x] == cur)
				{
					board[idx][x] = cur * 2;
					idx++;
				}
				else
				{
					idx++;
					board[idx][x] = cur;
				}
			}
		}
	}
	else
	{
		for (int x = 0; x < N; x++)
		{
			for (int y = N - 1; y >= 0; y--)
			{
				if (board[y][x])
					q.push(board[y][x]);
				board[y][x] = 0;
			}

			int idx = N - 1;
			while (!q.empty())
			{
				int cur = q.front();
				q.pop();

				if (board[idx][x] == 0)
					board[idx][x] = cur;
				else if (board[idx][x] == cur)
				{
					board[idx][x] = cur * 2;
					idx--;
				}
				else
				{
					idx--;
					board[idx][x] = cur;
				}
			}
		}
	}
}
void dfs(int count)
{
	if (count == 5)
	{
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				ans = ans < board[y][x] ? board[y][x] : ans;
		return;
	}

	vector<vector<int> > cur(board);

	for (int d = 0; d < 4; d++)
	{
		process(d);
		dfs(count + 1);

		board.assign(cur.begin(), cur.end());
	}
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N;
	board.resize(N, vector<int>(N));
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> board[y][x];

	dfs(0);
	cout << ans;
}