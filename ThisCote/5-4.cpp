/*
이것이 코테다
DFS/BFS - 미로 탈출
아주 흔한 DFS/BFS 문제
*/
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
vector<string> board;
vector<vector<bool> > check;
vector<vector<int> > steps;
int N, M;
bool isValid(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < M;
}
void bfs()
{
	queue<pair<int, int> > q;
	q.push(make_pair(0, 0));
	while (!q.empty())
	{
		int cx = q.front().first, cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int dx = cx + dir[i][0], dy = cy + dir[i][1];
			if (isValid(dx, dy) && steps[dx][dy] == 1 && board[dx][dy] == '1')
			{
				steps[dx][dy] = steps[cx][cy] + 1;
				q.push(make_pair(dx, dy));
			}
		}
	}
}
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	string str;

	cin >> N >> M;

	board.resize(N);
	for (int i = 0; i < N; i++)
		cin >> board[i];

	steps.resize(N, vector<int>(M, 1));

	bfs();

	cout << steps[N - 1][M - 1];
}