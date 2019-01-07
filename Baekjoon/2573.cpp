#include <iostream>
#include <vector>
using namespace std;
int dir[4][2] = {
{1,0},
{0,1},
{-1,0},
{0,-1}
};
int w, h;
vector<vector<int> > curMap;
vector<vector<int> > nextMap;
vector<vector<bool> > visit;
void dfs(int y, int x)
{
	visit[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dir[i][0], nx = x + dir[i][1];

		if (((ny >= 0 && ny < h) && (nx >= 0 && nx < w))
			&& (visit[ny][nx] == false && curMap[ny][nx] > 0))
			dfs(ny, nx);
	}
}
void melt(int y, int x)
{
	int water = 0;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dir[i][0], nx = x + dir[i][1];
		if ((ny >= 0 && ny < h) && (nx >= 0 && nx < w) && curMap[ny][nx] == 0)
			water++;
	}
	nextMap[y][x] = ((curMap[y][x] - water) > 0) ? (curMap[y][x] - water) : 0;
}
bool isGone()
{
	int ice = 0;
	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
			if (curMap[y][x] > 0)
				return false;
	return true;
}
int main(void)
{
	cin >> h >> w;
	curMap = vector<vector<int> >(h, vector<int>(w));
	nextMap = vector<vector<int> >(h, vector<int>(w));
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> curMap[i][j];
	int year = 0;
	while (1)
	{
		if (isGone())
		{
			cout << 0;
			return 0;
		}
		visit = vector<vector<bool> >(h, vector<bool>(w, false));
		int island = 0;
		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				if (curMap[y][x] && visit[y][x] == false)
				{
					dfs(y, x);
					island++;
					if (island > 1)
					{
						cout << year;
						return 0;
					}
				}
			}
		}

		for (int y = 0; y < h; y++)
			for (int x = 0; x < w; x++)
				if (curMap[y][x])
					melt(y, x);
		curMap = nextMap;
		year++;
	}
	return 0;
}