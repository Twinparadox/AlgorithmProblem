#include <iostream>
using namespace std;
int main(void)
{
	int a1, a2, a3, d, r;
	while (1)
	{
		cin >> a1 >> a2 >> a3;
		if (a1 == 0 && a2 == 0 && a3 == 0)
			break;
		if (a2 - a1 == a3 - a2)
		{
			d = a2 - a1;
			cout << "AP " << a3 + d << '\n';
		}
		else
		{
			r = a2 / a1;
			cout << "GP " << a3 * r << '\n';
		}
	}
}
