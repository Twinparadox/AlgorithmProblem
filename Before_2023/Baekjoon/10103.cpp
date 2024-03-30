#include <iostream>
using namespace std;
int main(void)
{
	int n, a, b, as = 100, bs = 100;
	cin >> n;
	while (n--)
	{
		cin >> a >> b;
		if (a > b)
			bs -= a;
		else if (a < b)
			as -= b;
	}
	cout << as << '\n' << bs;
}
