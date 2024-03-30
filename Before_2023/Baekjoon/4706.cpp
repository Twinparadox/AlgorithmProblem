#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
	double a, b, s;
	while (1)
	{
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;
		double tmp = b / a;
		tmp = pow(tmp, 2);
		s = sqrt(1 - tmp);
		cout << fixed;
		cout.precision(3);
		cout << s << '\n';
	}
}
