/*
[G4] 알고스팟
아주 기초적인 BFS
1을 지날 때마다 벽을 한 번 뚫은 것이고, 그 지점에 도착하는 수를 카운트
이전 경로 중에 가장 벽을 적게 뚫고 오는 경로가 있으면 해당 경로가 최적 경로
*/
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int N, M;
vector<string> board;
vector<vector<int> > broken;
int dir[4][2] = {
	{1, 0}, {-1, 0}, {0,1}, {0,-1}
};
bool isValid(int x, int y)
{
	return x >= 0 && x < M && y >= 0 && y < N;
}
void BFS()
{
	queue<pair<int, int> > q;
	q.push(make_pair(0, 0));
	broken[0][0] = 0;
	while (!q.empty())
	{
		int cx = q.front().first, cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dir[i][0], ny = cy + dir[i][1];

			if (isValid(nx, ny))
			{
				if (board[ny][nx] == '0')
				{
					if (broken[ny][nx] > broken[cy][cx])
					{
						broken[ny][nx] = broken[cy][cx];
						q.push(make_pair(nx, ny));
					}
				}
				else
				{
					if (broken[ny][nx] > broken[cy][cx] + 1)
					{
						broken[ny][nx] = broken[cy][cx] + 1;
						q.push(make_pair(nx, ny));
					}
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
	cin >> M >> N;

	board.resize(N);
	broken.resize(N, vector<int>(M, 1e5));
	for (int i = 0; i < N; i++)
		cin >> board[i];

	BFS();
	cout << broken[N - 1][M - 1];
}