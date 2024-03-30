#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
	long long c, k, t;
	cin >> c >> k;
	t = pow(10, k);
	cout << (c + (t / 2)) / t * t;
}
