#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
	int n, x, result, itmp;
	double dtmp;
	cin >> n;
	while (n--)
	{
		cin >> x;
		for (itmp = 0; pow(10, itmp) < x; itmp++);
		result = x;
		for (int i = 1; i < itmp; i++)
		{
			dtmp = (double)x / pow(10, i);
			result = (int)(dtmp + 0.5);
			result = result*pow(10, i);
			x = result;
		}
		cout << result << '\n';
	}
}
