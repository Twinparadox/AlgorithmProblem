#include <iostream>
using namespace std;
int main(void)
{
	int t, c, q, d, n, p;
	cin >> t;
	while (t--)
	{
		cin >> c;
		q = d = n = p = 0;
		while (c > 0)
		{
			if (c >= 25)
				q = c / 25, c -= 25 * q;
			else if (c >= 10)
				d = c / 10, c -= 10 * d;
			else if (c >= 5)
				n = c / 5, c -= 5 * n;
			else
				p = c, c -= p;
		}
		cout << q << " " << d << " " << n << " " << p << "\n";
	}
}
