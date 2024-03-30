#include <iostream>
using namespace std;
int main(void)
{
	double temp, n;
	cin >> temp;
	while (1)
	{
		cin >> n;
		if (n == 999)
			break;
		cout.precision(2);
		cout << fixed << n - temp << '\n';
		temp = n;
	}
}
