#include <iostream>
using namespace std;
int main(void)
{
	int n, tmp;
	cin >> n;
	tmp = n;
	for (int i = 2; i*i <= tmp; i++)
	{
		while (n%i == 0)
		{
			n /= i;
			cout << i << '\n';
		}
	}
	if (n != 1)
		cout << n;
}
