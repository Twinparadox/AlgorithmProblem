#include <iostream>
using namespace std;
int main(void)
{
	int cnt, ans;
	double a, b, c, d, max = 0, tmp;
	cin >> a >> b >> c >> d;

	for (cnt = 0; cnt < 4; cnt++)
	{
		switch (cnt)
		{
		case 0:
			tmp = a / c + b / d;
			break;
		case 1:
			tmp = c / d + a / b;
			break;
		case 2:
			tmp = d / b + c / a;
			break;
		case 3:
			tmp = b / a + d / c;
			break;
		}
		if (tmp > max)
			max = tmp, ans = cnt;
	}
	cout << ans;
}
