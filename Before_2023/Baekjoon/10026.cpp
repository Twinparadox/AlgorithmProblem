#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int N;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
vector<string> arr;
vector<vector<bool> > check;
bool isValid(int coord)
{
	return coord >= 0 && coord < N;
}
void BFS(int i, int j, int RGB)
{
	queue<pair<int, int> > q;
	q.push(make_pair(i, j));
	check[i][j] = true;
	while (!q.empty())
	{
		int cx = q.front().first, cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dir[i][0], ny = cy + dir[i][1];
			if (isValid(nx) && isValid(ny) && !check[nx][ny])
			{
				if (RGB == 0 && (arr[nx][ny] == 'R' || arr[nx][ny] == 'G'))
				{
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
				if (RGB == 1 && arr[nx][ny] == 'R')
				{
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
				else if (RGB == 2 && arr[nx][ny] == 'G')
				{
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
				else if (RGB == 3 && arr[nx][ny] == 'B')
				{
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}
int main(void)
{
	int ans1 = 0, ans2 = 0;
	cin >> N;
	arr = vector<string>(N);
	check = vector<vector<bool> >(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!check[i][j])
			{
				ans1++;
				if (arr[i][j] == 'R')
					BFS(i, j, 1);
				else if (arr[i][j] == 'G')
					BFS(i, j, 2);
				else
					BFS(i, j, 3);
			}
		}
	}

	check = vector<vector<bool> >(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!check[i][j])
			{
				ans2++;
				if (arr[i][j] == 'R' || arr[i][j] == 'G')
					BFS(i, j, 0);
				else if (arr[i][j] == 'B')
					BFS(i, j, 3);
			}
		}
	}

	cout << ans1 << ' ' << ans2;
}