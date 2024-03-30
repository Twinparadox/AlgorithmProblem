#include <iostream>
using namespace std;
int main(void)
{
	long long a, b, c;
	while (1)
	{
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;

		long long min, tmp, ans;
		min = (a + b) / 2;

		tmp = 2 * a - b;
		if (tmp < min)
			min = tmp;

		tmp = 2 * b - a;
		if (tmp < min)
			min = tmp;

		cout << min << '\n';
	}
}