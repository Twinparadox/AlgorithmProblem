#include <iostream>
using namespace std;
int main(void)
{
	int a, b, c, d, e, sum = 0;
	cin >> a >> b >> c >> d >> e;
	if (a < 0)
	{
		sum += (-a * c);
		a = 0;
	}
	if (a == 0)
	{
		sum += d;
	}
	sum += (b - a)*e;
	cout << sum;
}
