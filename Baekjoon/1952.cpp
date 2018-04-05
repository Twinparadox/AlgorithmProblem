#include <iostream>
using namespace std;
int main(void)
{
	int m, n;
	int arr[101][101] = { 0, }, cnt = 0, step = 0, d[4][2] = { {1,0},{0,1},{-1,0},{0,-1} }, dir = 0, x, y;
	cin >> m >> n;
	x = y = 1, arr[y][x] = 1;
	while (step < m*n - 1)
	{
		int dx = x + d[dir][0], dy = y + d[dir][1];
		if ((dx > n || dx <= 0 || dy > m || dy <= 0) || arr[dy][dx])
			dir = (dir + 1) % 4, cnt++;
		else
			x = dx, y = dy, arr[dy][dx]++, step++;
	}
	cout << cnt;
}
