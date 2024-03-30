#include <iostream>
using namespace std;
int main(void)
{
	int arr[101][101] = { 0, };
	int n, m, x1, y1, x2, y2, sum = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		for (int x = x1; x <= x2; x++)
			for (int y = y1; y <= y2; y++)
				arr[x][y]++;
	}
	for (int i = 1; i <= 100; i++)
	{
		for (int j = 1; j <= 100; j++)
		{
			if (arr[i][j] > m)
				sum++;
		}
	}
	cout << sum;
}
