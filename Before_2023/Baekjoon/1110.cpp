#include <iostream>
using namespace std;
int main(void)
{
	int n, x, cnt = 1;
	cin >> n;
	if (n < 10)
		x = n * 10 + n;
	else
		x = (n / 10 + n % 10) % 10 + (n % 10) * 10;
	while(x != n)
	{
		if (x < 10)
			x = x * 10 + x;
		else
			x = (x / 10 + x % 10) % 10 + (x % 10) * 10;
		cnt++;
	}
	cout << cnt;
}
