#include <iostream>
using namespace std;
int main(void)
{
	int t, n;
	double c, g, sum1, sum2;
	cin >> t;
	cout.precision(1);
	while (t--)
	{
		sum1 = sum2 = 0.0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> c >> g;
			sum1 += g*c;
			sum2 += c;
		}
		cout << (int)sum2 << " " << fixed << (double)sum1 / sum2 << "\n";
	}
}
