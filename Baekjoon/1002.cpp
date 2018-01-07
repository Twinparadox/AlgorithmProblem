#include <iostream>
using namespace std;
int main(void)
{
	int t;
	int x1, y1, r1, x2, y2, r2, dist, r;
	cin >> t;
	while (t--)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		dist = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
		if (x1 == x2 && y1 == y2)
		{
			if (r1 == r2)
				cout << -1;
			else
				cout << 0;
		}
		else
		{
			if (dist > (r1 - r2)*(r1 - r2) && dist < (r1 + r2)*(r1 + r2))
				cout << 2;
			else if (dist == (r1 + r2)*(r1 + r2) || dist == (r1 - r2)*(r1 - r2))
				cout << 1;
			else if (dist > (r1 + r2)*(r1 + r2) || dist < (r1 - r2)*(r1 - r2))
				cout << 0;
		}
		cout << '\n';
	}
}
