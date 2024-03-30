#include <iostream>
using namespace std;
int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}
int main(void)
{
	int t, a, b;
	cin >> t;
	while (t--)
	{
		int g;
		cin >> a >> b;
		g = gcd(a, b);
		cout << a*b / g << " " << g << "\n";
	}
}
