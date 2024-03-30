#include <iostream>
using namespace std;
int main(void)
{
	int t, n;
	int sum1, sum2;
	double c, g;
	cin >> t;
	cout.precision(1);
	while (t--)
	{
		sum1 = sum2 = 0.0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> c >> g;
			sum1 += g * 10 * c;
			sum2 += c;
		}

		int tmp = (int)((double)sum1 / sum2 + 0.5) * 10;
		cout << (int)sum2 << " " << fixed << (double)tmp / 100 << "\n";
	}
}