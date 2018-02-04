#include <iostream>
using namespace std;
long long a, b, c;
long long calc(long long a, long long b)
{
	if (b == 0)
		return 1;
	else if (b % 2 == 0)
	{
		long long tmp = calc(a, b / 2);
		return ((tmp%c)*(tmp%c)) % c;
	}
	else
	{
		return ((a%c)*(calc(a, b - 1) % c)) % c;
	}
}
int main(void)
{
	cin >> a >> b >> c;
	cout << calc(a%c, b) % c;
}
