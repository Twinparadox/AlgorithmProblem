#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int T;

	cin >> T;
	while (T--)
	{
		int n, heils, max;
		cin >> n;
		heils = max = n;
		while (heils != 1)
		{
			if (max < heils)
				max = heils;
			if (heils % 2 == 0)
				heils /= 2;
			else
				heils = heils * 3 + 1;
		}
		cout << max << '\n';
	}
}