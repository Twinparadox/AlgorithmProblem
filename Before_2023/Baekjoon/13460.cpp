/*
[G2] - 13460 구슬 탈출 2
BFS나 DFS로 풀 수 있음
구슬이 상화좌우로 움직이는 부분을 처리해야 하는 것도 필요함
구슬을 한번에 이동할 수 있는 최대치로 옮긴 후에,
공이 겹치거나, 구멍에 한 번에 여러 개가 들어간 경우를 체크
13459 문제는 횟수가 아닌 1과 0만 출력함
*/
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
struct Ball
{
	int redX, redY, blueX, blueY, cnt;
};
int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
vector<string> board;
int N, M;
int bfs(Ball start)
{
	int ans = -1;

	bool check[10][10][10][10] = { false, };
	queue<Ball> q;

	q.push(start);
	check[start.redY][start.redX][start.blueY][start.blueX] = true;

	while (!q.empty())
	{
		Ball cur = q.front();
		q.pop();

		if (cur.cnt > 10)
			break;
		if (board[cur.redY][cur.redX] == 'O' && board[cur.blueY][cur.blueX] != 'O')
		{
			ans = cur.cnt;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int nextRY = cur.redY, nextRX = cur.redX;
			int nextBY = cur.blueY, nextBX = cur.blueX;

			while (1)
			{
				if (board[nextRY][nextRX] != '#' && board[nextRY][nextRX] != 'O')
					nextRY += dir[i][0], nextRX += dir[i][1];
				else
				{
					if (board[nextRY][nextRX] == '#')
						nextRY -= dir[i][0], nextRX -= dir[i][1];
					break;
				}
			}
			while (1)
			{
				if (board[nextBY][nextBX] != '#' && board[nextBY][nextBX] != 'O')
					nextBY += dir[i][0], nextBX += dir[i][1];
				else
				{
					if (board[nextBY][nextBX] == '#')
						nextBY -= dir[i][0], nextBX -= dir[i][1];
					break;
				}
			}
			if (nextRY == nextBY && nextRX == nextBX)
			{
				if (board[nextRY][nextRX] != 'O')
				{
					int distR = abs(nextRY - cur.redY) + abs(nextRX - cur.redX);
					int distB = abs(nextBY - cur.blueY) + abs(nextBX - cur.blueX);
					if (distR > distB)
						nextRY -= dir[i][0], nextRX -= dir[i][1];
					else
						nextBY -= dir[i][0], nextBX -= dir[i][1];
				}
			}

			if (!check[nextRY][nextRX][nextBY][nextBX])
			{
				check[nextRY][nextRX][nextBY][nextBX] = true;
				q.push({ nextRX, nextRY, nextBX, nextBY, cur.cnt + 1 });
			}
		}
	}

	return ans;
}
int main(void)
{
	Ball loc;

	cin >> N >> M;
	board.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> board[i];
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 'R')
				loc.redX = j, loc.redY = i;
			else if (board[i][j] == 'B')
				loc.blueX = j, loc.blueY = i;
		}
	}
	loc.cnt = 0;

	cout << bfs(loc);
}