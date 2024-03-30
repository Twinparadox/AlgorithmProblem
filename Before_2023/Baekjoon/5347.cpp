#include <iostream>
using namespace std;
long long gcd(long long a, long long b)
{
	if (b == 0)
		return a;
	return gcd(b, a%b);
}
int main(void)
{
	int t;
	long long a, b, g;
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		if (a > b)
			g = gcd(a, b);
		else
			g = gcd(b, a);
		cout << a*b / g << '\n';
	}
}
