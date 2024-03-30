#include <iostream>
using namespace std;
int main(void)
{
	int m, loc = 1, x, y;
	cin >> m;
	while (m--)
	{
		cin >> x >> y;
		if (x == loc)
			loc = y;
		else if (y == loc)
			loc = x;
	}
	cout << loc;
}
