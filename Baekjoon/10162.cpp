#include <iostream>
using namespace std;
int main(void)
{
	int t, a = 0, b = 0, c = 0;
	cin >> t;
	if (t % 10 != 0)
		cout << -1;
	else
	{
		while (t > 0)
		{
			if (t >= 300)
				a = t / 300, t -= (t / 300) * 300;
			else if (t >= 60)
				b = t / 60, t -= (t / 60) * 60;
			else
				c = t / 10, t = 0;
		}
		cout << a << " " << b << " " << c;
	}
}
