#include <iostream>
using namespace std;
long long gcd(long long a, long long b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}
int main(void)
{
	std::ios::sync_with_stdio(false);
	long long a, b, g;
	cin >> a >> b;
	if (a > b)
		g = gcd(a, b);
	else
		g = gcd(b, a);
	for (int i = 0; i < g; i++)
		cout << 1;
}
