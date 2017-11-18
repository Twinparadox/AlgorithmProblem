#include <iostream>
using namespace std;
int main(void)
{
	long long s, n;
	cin >> s;
	for (n = 1; (n*(n + 1) / 2) <= s; n++);
	cout << n - 1;
}
