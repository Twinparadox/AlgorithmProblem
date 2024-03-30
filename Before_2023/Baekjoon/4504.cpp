#include <iostream>
using namespace std;
int main(void)
{
	int n, k;
	cin >> n;
	while (1)
	{
		cin >> k;
		if (k == 0)
			break;
		else
		{
			if (k%n == 0)
				cout << k << " is a multiple of " << n << ".\n";
			else
				cout << k << " is NOT a multiple of " << n << ".\n";
		}
	}
}
