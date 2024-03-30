#include <iostream>
using namespace std;
int main(void)
{
	int a, b, c;
	long long n;
	cin >> a >> b >> c;
	if (b >= c)
		cout << -1;
	else
		cout << a / (c - b) + 1;
}
