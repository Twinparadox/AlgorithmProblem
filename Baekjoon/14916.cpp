#include <iostream>
using namespace std;
int main(void)
{
	int n;
	int co2 = 0, co5 = 0;
	cin >> n;
	co5 = n / 5;
	n = n - (n / 5) * 5;
	co2 = n / 2;
	n = n - (n / 2) * 2;
	if (n == 1)
	{
		if (co5 == 0)
		{
			cout << -1;
		}
		else
		{
			co5--;
			co2 += 3;
			cout << co5 + co2;
		}
	}
	else
	{
		cout << co5 + co2;
	}
}
