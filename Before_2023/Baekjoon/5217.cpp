#include <iostream>
using namespace std;
int main(void)
{
	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		cout << "Pairs for " << n << ": ";

		for (int i = 1; i <= n / 2; i++)
		{
			if (n - i == i)
				break;
			else
			{
				cout << i << " " << n - i;
				if (i != n / 2 && i + 1 != n - i - 1)
					cout << ", ";
			}
		}
		cout << '\n';
	}
}