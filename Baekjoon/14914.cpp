#include <iostream>
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
	int a, b, g;
	cin >> a >> b;
	g = gcd(a, b);

	for (int i = 1; i <= g; i++)
		if (g%i == 0)
			cout << i << ' ' << a / i << ' ' << b / i << '\n';
}
