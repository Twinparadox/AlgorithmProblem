/*
이것이 코테다
구현 - 상하좌우
그냥 막 움직이면 되는 문제
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int N;
bool isValid(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < N;
}
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	string op;
	int cx, cy, dx, dy, len;
	int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

	cin >> N;
	cin.ignore();
	getline(cin, op);
	len = op.length();
	cx = cy = 0;
	for (int i = 0; i < len; i += 2)
	{
		switch (op[i])
		{
		case 'R':
			dx = cx + dir[0][0];
			dy = cy + dir[0][1];
			if (isValid(dx, dy))
				cx = dx, cy = dy;
			break;
		case 'L':
			dx = cx + dir[1][0];
			dy = cy + dir[1][1];
			if (isValid(dx, dy))
				cx = dx, cy = dy;
			break;
		case 'D':
			dx = cx + dir[2][0];
			dy = cy + dir[2][1];
			if (isValid(dx, dy))
				cx = dx, cy = dy;
			break;
		case 'U':
			dx = cx + dir[3][0];
			dy = cy + dir[3][1];
			if (isValid(dx, dy))
				cx = dx, cy = dy;
			break;
		}
	}
	cout << cy + 1 << ' ' << cx + 1;
}