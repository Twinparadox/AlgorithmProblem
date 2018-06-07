#include <iostream>
using namespace std;
int main(void)
{
	int a, d, k, n;
	cin >> a >> d >> k;
	k -= a;
	if (k%d != 0)
		cout << 'X';
	else
	{
		if (k / d < 0)
			cout << 'X';
		else
			cout << k / d + 1;
	}
}
