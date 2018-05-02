#include <iostream>
using namespace std;
int main(void)
{
	int min = 101, tmp, t = 7, sum = 0;
	while (t--)
	{
		cin >> tmp;
		if (tmp % 2 == 1)
		{
			sum += tmp;
			if (min > tmp)
				min = tmp;
		}
	}
	if (min == 101)
		cout << -1;
	else
		cout << sum << "\n" << min;
}
