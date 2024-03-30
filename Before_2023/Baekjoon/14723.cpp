#include <iostream>
using namespace std;
int main(void)
{
	int n, a, b;
	cin >> n;
	for (a = 1; a*(a + 1) / 2 < n; a++);
	b = (a*(a + 1) / 2) - n;
	cout << b + 1 << ' ' << a - b;
}
