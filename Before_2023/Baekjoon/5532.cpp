#include <iostream>
using namespace std;
int main(void)
{
	int l, a, b, c, d, result;
	cin >> l >> a >> b >> c >> d;
	result = l - ((a + c - 1) / c < (b + d - 1) / d ? (b + d - 1) / d : (a + c - 1) / c);
	if (result > 0)
		cout << result;
	else
		cout << 0;
}
