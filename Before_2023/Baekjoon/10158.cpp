#include <iostream>
using namespace std;
int main(void)
{
	int w, h, curx, cury, dx, dy, t;
	cin >> w >> h >> curx >> cury >> t;
	dx = dy = 1;
	for (int i = 0; i < t; i++)
	{
		if (curx + dx > w || curx + dx < 0)
			dx = -dx;
		if (cury + dy > h || cury + dy < 0)
			dy = -dy;
		curx += dx;
		cury += dy;
	}
	cout << curx << ' ' << cury;
}
