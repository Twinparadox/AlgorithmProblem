#include <iostream>
#include <string>
#include <vector>
using namespace std;
int R, C;
vector<string> arr;
bool isAble(int startX, int startY, int broken)
{
	int cntCar = 0, cntWall = 0;
	for (int i = startX; i <= startX + 1; i++)
	{
		for (int j = startY; j <= startY + 1; j++)
		{
			if (arr[i][j] == 'X')
				cntCar++;
			if (arr[i][j] == '#')
			{
				cntWall++;
				break;
			}
		}
	}

	if (cntWall)
		return false;
	if (cntCar != broken)
		return false;
	else
		return true;
}
int main(void)
{
	cin >> R >> C;
	arr = vector<string>(R);
	for (int i = 0; i < R; i++)
		cin >> arr[i];

	for (int broken = 0; broken <= 4; broken++)
	{
		int cnt = 0;
		for (int x = 0; x < R - 1; x++)
			for (int y = 0; y < C - 1; y++)
				if (isAble(x, y, broken))
					cnt++;

		cout << cnt << '\n';
	}
}