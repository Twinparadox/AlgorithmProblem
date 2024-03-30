#include <iostream>
using namespace std;
int main(void)
{
	const float BR = 350.34, VIS = 230.90, AUD = 190.55, ARM = 125.30, LEG = 180.90;
	int t, a, b, c, d, e;
	double sum = 0.0;
	cin >> t;
	cout.precision(2);
	while (t--)
	{
		cin >> a >> b >> c >> d >> e;
		cout << "$" << fixed << a*BR + b*VIS + c*AUD + d*ARM + e*LEG << "\n";
	}
}
