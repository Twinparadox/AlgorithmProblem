#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool check(int x, int y, int size, vector<string> &arr)
{
	int nx = x + size - 1, ny = y + size - 1;
	if (arr[x][y] != arr[x][ny] || arr[x][y] != arr[nx][y] || arr[x][y] != arr[nx][ny])
		return false;
	return true;
}
int main(void)
{
	int N, M, max;
	cin >> N >> M;

	vector<string> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	if (N < M)
		max = N;
	else
		max = M;

	while (max > 1)
	{
		for (int i = 0; i <= N - max; i++)
		{
			for (int j = 0; j <= M - max; j++)
			{
				if (check(i, j, max, arr))
				{
					cout << max * max;
					return 0;
				}
			}
		}
		max--;
	}
	cout << max;
	return 0;
}