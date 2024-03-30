#include <math.h>
#include <iostream>
#include <set>
using namespace std;
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}
int main(void)
{
	int r, g, c;
	set<int> meta;
	cin >> r >> g;

	if (r > g)
		c = gcd(r, g);
	else
		c = gcd(g, r);

	for (int i = 1; i <= sqrt(c); i++)
	{
		if (c%i == 0)
		{
			if (c / i == i)
				meta.insert(i);
			else
				meta.insert(i), meta.insert(c / i);
		}
	}

	for (set<int>::iterator iter = meta.begin(); iter != meta.end(); iter++)
		cout << *iter << ' ' << r / (*iter) << ' ' << g / (*iter) << '\n';
}