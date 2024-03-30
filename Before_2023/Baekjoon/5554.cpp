#include <iostream>
using namespace std;
int main(void)
{
	int a, b, c, d, x, y, sum;
	cin >> a >> b >> c >> d;
	sum = a + b + c + d;
	x = sum / 60;
	y = sum % 60;
	cout << x << endl << y;
}
