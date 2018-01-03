#include <iostream>
using namespace std;
int main(void)
{
	long long a, b, result;
	cin >> a >> b;
	if (a > b)
	{
		cout << a - b - 1 << '\n';
		for (long long i = b + 1; i< a; i++)
			cout << i << ' ';
	}
	else if (a == b)
	{
		cout << 0;
	}
	else
	{
		cout << b - a - 1 << '\n';
		for (long long i = a + 1; i < b; i++)
			cout << i << ' ';
	}
}
