#include <iostream>
using namespace std;
int main(void)
{
	int x1, x2, x3, y1, y2, y3, tmp;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	tmp = x1 * y2 + x2 * y3 + x3 * y1;
	tmp -= (y1 * x2 + y2 * x3 + y3 * x1);
	if (tmp > 0)
		cout << 1;
	else if (tmp < 0)
		cout << -1;
	else
		cout << 0;
}
