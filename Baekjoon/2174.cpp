/* [G5] 2174 - 로봇 시뮬레이션 */
/*
좌표, 로봇 동작 등이 헷갈릴 수 있는 문제
시뮬레이션 문제로, 알고리즘 자체는 어려운 문제가 아님
*/
#include <iostream>
#include <vector>
using namespace std;
int dir[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
int A, B, N, M;
bool isValid(int x, int y)
{
	return x >= 0 && x < A && y >= 0 && y < B;
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	vector<int> directions;
	vector<vector<int> > board;
	vector<pair<int, int> > robots;
	bool flag = true;

	cin >> A >> B;
	cin >> N >> M;

	board.resize(B, vector<int>(A, -1));
	robots.resize(N);
	directions.resize(N);
	for (int i = 0; i < N; i++)
	{
		int x, y;
		char op;
		cin >> x >> y >> op;

		x--;
		robots[i] = make_pair(x, B - y);
		board[B - y][x] = i;
		if (op == 'E')
		{
			directions[i] = 1;
		}
		else if (op == 'W')
		{
			directions[i] = 3;
		}
		else if (op == 'N')
		{
			directions[i] = 2;
		}
		else
		{
			directions[i] = 0;
		}
	}
	for (int i = 0; i < M; i++)
	{
		int robot, iter;
		char op;
		cin >> robot >> op >> iter;
		robot--;

		if (op == 'F')
		{
			for (int j = 0; j < iter; j++)
			{
				int nx = robots[robot].first + dir[directions[robot]][0];
				int ny = robots[robot].second + dir[directions[robot]][1];

				if (isValid(nx, ny))
				{
					if (board[ny][nx] != -1)
					{
						if (flag)
						{
							flag = false;
							cout << "Robot " << robot + 1 << " crashes into robot " << board[ny][nx] + 1 << '\n';
						}
					}
					else
					{
						board[robots[robot].second][robots[robot].first] = -1;
						board[ny][nx] = robot;
						robots[robot] = make_pair(nx, ny);
					}
				}
				else if (flag)
				{
					flag = false;
					cout << "Robot " << robot + 1 << " crashes into the wall\n";
				}
			}
		}
		else if (op == 'R')
		{
			iter %= 4;
			if (directions[robot] - iter < 0)
				directions[robot] += 4;

			directions[robot] -= iter;
		}
		else
		{
			iter %= 4;
			directions[robot] = (directions[robot] + iter) % 4;
		}
	}
	if (flag)
		cout << "OK";
}