#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
	int k, x;
	cin >> k;
	x = (int)(-0.5 + 0.5*sqrt(1 - 4 * (1 - k)));
	cout << x;
}
