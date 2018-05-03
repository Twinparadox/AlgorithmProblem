#include <iostream>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	while (1)
	{
		if (n > 1 && n % 2 == 1)
		{
			cout << 0;
			return 0;
		}
		else if (n == 1)
			break;
		else
			n /= 2;
	}
	cout << 1;
	return 0;
}
