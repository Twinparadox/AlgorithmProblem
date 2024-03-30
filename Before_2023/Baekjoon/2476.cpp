#include <iostream>
using namespace std;
int main(void)
{
	int t, a, b, c, sum = 0, max = 0;
	cin >> t;
	while (t--)
	{
		cin >> a >> b >> c;
		if (a == b && b == c)
			sum = 10000 + a * 1000;
		else if (a == b)
			sum = 1000 + a * 100;
		else if (b == c)
			sum = 1000 + b * 100;
		else if (a == c)
			sum = 1000 + c * 100;
		else
			sum = ((a > b ? a : b) > c ? (a > b ? a : b) : c) * 100;
		if (max < sum)
			max = sum;
	}
	cout << max;
}
