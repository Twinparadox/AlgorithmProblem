#include <iostream>
#include <vector>
using namespace std;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int n;
vector<vector<int> > map;
vector<vector<bool> > check;
void DFS(int x, int y, int water)
{
	int nx, ny;
	check[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		nx = x + dir[i][0], ny = y + dir[i][1];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n)
			continue;
		if (map[nx][ny] - water > 0 && check[nx][ny] == false)
			DFS(nx, ny, water);
	}
}
int main(void)
{
	int maxArea = 0, maxHeight = 0;
	cin >> n;
	map = vector<vector<int> >(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] > maxHeight)
				maxHeight = map[i][j];
		}
	}


	for (int water = 0; water < maxHeight; water++)
	{
		check = vector<vector<bool> >(n, vector<bool>(n, false));
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (map[i][j] - water > 0 && check[i][j] == false)
				{
					cnt++;
					DFS(i, j, water);
				}
			}
		}
		maxArea = cnt < maxArea ? maxArea : cnt;
		check.clear();
	}
	cout << maxArea;
}