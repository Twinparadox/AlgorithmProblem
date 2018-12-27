#include <iostream>
#include <math.h>
using namespace std;
int gcd(int a, int b)
{
	if (a < b)
		return gcd(b, a);
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}
int main(void)
{
	long long g, l, div, ans, min;;
	cin >> g >> l;
	div = l / g;
	min = div, ans = 1;
	for (int i = 1; i <= sqrt(div); i++)
	{
		if (div%i == 0)
		{
			if (gcd(i, div / i) != 1)
				continue;
			if (abs(i - div / i) < min)
			{
				min = abs(i - div / i);
				ans = i;
			}
		}
	}

	cout << ans * g << ' ' << l / ans;
}