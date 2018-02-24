#include <iostream>
using namespace std;
int main(void)
{
	int x, y, ansx, ansy;
	ansx = ansy = 0;
	while (cin >> x >> y)
		ansx ^= x, ansy ^= y;
	cout << ansx << ' ' << ansy;
}
