#include <iostream>
using namespace std;
int main(void)
{
	int e, m, s, y, a, b, c;
	a = b = c = y = 1;
	cin >> e >> s >> m;
	while (1)
	{
		if (a == e && b == s && c == m)
			break;
		a++, b++, c++, y++;
		a = a > 15 ? 1 : a;
		b = b > 28 ? 1 : b;
		c = c > 19 ? 1 : c;
	}
	cout << y;
}
