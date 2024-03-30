#include <iostream>
using namespace std;
int main(void)
{
	int t, n, c;
	cin >> t;
	while (t--)
	{
		cin >> n >> c;
		if (n%c == 0)
			cout << n / c << '\n';
		else
			cout << n / c + 1 << '\n';
	}
}
