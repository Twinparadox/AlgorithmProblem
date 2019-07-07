#include <iostream>
using namespace std;
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a%b);
}
int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		int m, n, x, y, lcm, mg, ng;
		bool check = false;
		cin >> m >> n >> x >> y;
		if (n > m)
			lcm = gcd(n, m);
		else
			lcm = gcd(m, n);
		lcm = m * n / lcm;
		mg = lcm / m, ng = lcm / n;

		while (x <= lcm && (x - 1) % n + 1 != y)
			x += m;

		if (x > lcm)
			cout << -1;
		else
			cout << x;
		cout << '\n';
	}
}