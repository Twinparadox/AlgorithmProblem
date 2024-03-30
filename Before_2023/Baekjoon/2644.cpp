#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int bfs(vector<vector<int> > arr, int start, int dest)
{
	int size = arr.size();
	vector<int> table(size, 0);
	queue<int> q;

	q.push(start);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 1; i < size; i++)
		{
			if (arr[now][i] == 0 || table[i] != 0)
				continue;
			table[i] = table[now] + 1;
			q.push(i);
		}
	}

	return table[dest];
}
int main(void)
{
	int n, a, b, m, x, y;
	cin >> n >> a >> b;
	vector<vector<int> > family(n + 1, vector<int>(n + 1));

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		family[x][y] = family[y][x] = 1;
	}

	int ans = bfs(family, a, b);
	cout << ((ans == 0) ? -1 : ans);
}