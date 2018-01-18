#include <iostream>
using namespace std;
int main(void)
{
	int n, sum = 0, c, k;
	cin >> n;
	while (n--)
	{
		cin >> c >> k;
		if (k != 0)
			sum += c*k;
	}
	cout << sum;
}
