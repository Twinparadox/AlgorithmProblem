#include <iostream>
using namespace std;
int main(void)
{
	long long i, j;
	cin >> i >> j;
	if (j >= i)
		cout << (j - i + 1)*(i + j) / 2;
	else
		cout << (i - j + 1)*(i + j) / 2;
}
