#include <iostream>
using namespace std;
int main(void)
{
	int n, res;
	bool odd;

	for (int i = 1; ; i++)
	{
		cin >> n;
		if (n == 0)
			break;

		cout << i << ". ";
		if (n % 2 == 0)
			odd = false, res = n * 3 / 2;
		else
			odd = true, res = (n * 3 + 1) / 2;
		res *= 3;
		res /= 9;

		if (odd)
			cout << "odd ";
		else
			cout << "even ";
		cout << res << '\n';
	}

}