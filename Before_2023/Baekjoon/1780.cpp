#include <iostream>
#include <vector>
using namespace std;
int N, arr[3] = { 0, };
vector<vector<int> > matrix;
void check(int startX, int startY, int size)
{
	int su = matrix[startX][startY];

	if (size > 1)
	{
		bool flag = true;
		for (int x = startX; x < startX + size && flag; x++)
		{
			for (int y = startY; y < startY + size && flag; y++)
			{
				if (matrix[x][y] != su)
				{
					flag = false;
					break;
				}
			}
		}

		if (flag)
		{
			arr[su + 1]++;
		}
		else
		{
			int nextSize = size / 3;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					int x = startX + i * nextSize, y = startY + j * nextSize;
					check(x, y, nextSize);
				}
			}
		}
	}
	else
	{
		arr[su + 1]++;
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	cin >> N;
	matrix = vector<vector<int> >(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> matrix[i][j];

	check(0, 0, N);

	for (int i = 0; i < 3; i++)
		cout << arr[i] << '\n';
}