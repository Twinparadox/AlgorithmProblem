#include <iostream>
using namespace std;
int main(void)
{
	int n;
	long long a[46] = { 1, 0, }, b[46] = { 0, 1, };
	cin >> n;
	for (int i = 2; i <= n; i++)
		a[i] = a[i - 1] + a[i - 2], b[i] = b[i - 1] + b[i - 2];
	cout << a[n] << ' ' << b[n];
}
