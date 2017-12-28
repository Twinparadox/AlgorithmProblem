#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
	int min = 1000, tmp, a, b, n;
	cin >> a >> b >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (abs(b - tmp) < min)
			min = abs(b - tmp);
	}
	tmp = min;
	min = (tmp + 1) < abs(b - a) ? (tmp + 1) : abs(b - a);
	cout << min;
}
