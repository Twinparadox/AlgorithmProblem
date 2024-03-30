/*
이것이 코테다
구현 - 왕실의 나이트
8방향 탐색하는 구현
*/
#include <iostream>
#include <string>
using namespace std;
bool isValid(int x, int y)
{
	return x >= 1 && x <= 8 && y >= 1 && y <= 8;
}
int main(void)
{
	string loc;
	int cx, cy, dx, dy, cnt = 0;
	int dir[8][2] = { {2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2} };
	cin >> loc;

	cx = loc[0] - 'a' + 1;
	cy = loc[1] - '0';

	for (int i = 0; i < 8; i++)
	{
		dx = cx + dir[i][0], dy = cy + dir[i][1];
		if (isValid(dx, dy))
			cnt++;
	}
	cout << cnt;
}