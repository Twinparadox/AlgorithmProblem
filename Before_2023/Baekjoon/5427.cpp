/*
[G4] 불
문자열 처리와 BFS로 문제를 푸는 것
다만 불과 상근이를 동시에 움직일 때 신경써야 하고
되도록이면 불이 퍼지는 것부터 체크하고,
상근이가 움직일 수 있는 부분을 체크하면 풀이가 쉬움
*/
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
int W, H, sy, sx;
vector<string> arr;
vector<vector<bool> > check;
vector<pair<int, int> > fire;
int dir[4][2] = {
	{1, 0}, {-1, 0}, {0, 1}, {0, -1}
};
bool isValid(int x, int y)
{
	return x >= 0 && x < W && y >= 0 && y < H;
}
int BFS(void)
{
	queue<pair<int, int > > q;
	queue<pair<int, int> > qFire;
	q.push(make_pair(sy, sx));

	int size = fire.size();
	for (int i = 0; i < size; i++)
		qFire.push(fire[i]);

	int ans = 0;
	while (!q.empty())
	{
		size = qFire.size();
		for (int i = 0; i < size; i++)
		{
			int y = qFire.front().first;
			int x = qFire.front().second;
			qFire.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dir[i][0];
				int nx = x + dir[i][1];

				if (isValid(nx, ny) && arr[ny][nx] == '.')
				{
					arr[ny][nx] = '*';
					qFire.push(make_pair(ny, nx));
				}
			}
		}

		size = q.size();
		for (int i = 0; i < size; i++)
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			if (y == 0 || y == H - 1 || x == 0 || x == W - 1)
				return ans + 1;

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dir[i][0];
				int nx = x + dir[i][1];

				if (isValid(nx, ny) && !check[ny][nx] && arr[ny][nx] != '#' && arr[ny][nx] != '*')
				{
					check[ny][nx] = true;
					q.push(make_pair(ny, nx));
				}
			}
		}
		ans++;
	}
	return -1;
}
int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> W >> H;
		arr = vector<string>(H);
		check = vector<vector<bool> >(H, vector<bool>(W, false));
		fire.clear();
		for (int y = 0; y < H; y++)
		{
			cin >> arr[y];
			for (int x = 0; x < W; x++)
			{
				switch (arr[y][x])
				{
				case '*':
					fire.push_back(make_pair(y, x));
					break;
				case '@':
					sy = y, sx = x;
					break;
				default:
					break;
				}
			}
		}
		int ans = BFS();
		if (ans == -1)
			cout << "IMPOSSIBLE\n";
		else
			cout << ans << '\n';
	}
}