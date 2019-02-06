#include <iostream>
using namespace std;
int main(void)
{
	double a, b;
	cout.precision(2);
	while (cin >> a >> b)
	{
		double ans = (double)a / b;
		int tmp = (ans + 0.005) * 100;
		ans = (double)tmp / 100;
		cout << fixed << ans << '\n';
	}
}