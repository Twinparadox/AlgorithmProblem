#include <iostream>
using namespace std;
int main(void)
{
	long long wine = 0, c, k, p;
	cin >> c >> k >> p;
	wine = (k*c*(c + 1) / 2) + p * (c*(c + 1)*(2 * c + 1) / 6);
	cout << wine;
}