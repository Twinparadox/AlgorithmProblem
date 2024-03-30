#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
	int a, b, c, d;
	while (1)
	{
		cin >> a >> b >> c >> d;
		if (a == 0 && b == 0 && c == 0 && d == 0)
			break;
		int cnt = 0, ta, tb, tc, td;
		while (a != b || b != c || c != d || a != d)
		{
			ta = a, tb = b, tc = c, td = d;
			a = abs(ta - tb), b = abs(tb - tc), c = abs(tc - td), d = abs(td - ta);
			cnt++;
		}
		cout << cnt << '\n';
	}
}
