#include <iostream>
using namespace std;
int main(void)
{
	int a, b, c, d, p;
	int suma, sumb;
	cin >> a >> b >> c >> d >> p;
	suma = sumb = 0;
	suma = a*p;
	if (p <= c)
		sumb = b;
	else
		sumb = b + (p - c)*d;
	cout << (suma < sumb ? suma : sumb);
}
