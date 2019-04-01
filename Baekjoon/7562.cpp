#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dir[8][2] = { {1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1} };
int distX, distY, N;
vector<vector<bool> > check;
struct coord
{
	int time;
	int x;
	int y;
};
bool isValid(int x, int y)
{
	return (x >= 0 && x < N) && (y >= 0 && y < N);
}
int BFS(int x, int y)
{
	queue<struct coord> q;
	q.push({ 0,x,y });
	check[x][y] = true;
	while (!q.empty())
	{
		int cx = q.front().x, cy = q.front().y, time = q.front().time;
		q.pop();
		if (cx == distX && cy == distY)
			return time;
		for (int i = 0; i < 8; i++)
		{
			int nx = cx + dir[i][0], ny = cy + dir[i][1];
			if (isValid(nx, ny) && !check[nx][ny])
			{
				q.push({ time + 1, nx, ny });
				check[nx][ny] = true;
			}
		}
	}
}
int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> N;
		check = vector<vector<bool> >(N, vector<bool>(N, false));
		int startX, startY;
		cin >> startX >> startY;
		cin >> distX >> distY;

		cout << BFS(startX, startY) << '\n';
	}
}