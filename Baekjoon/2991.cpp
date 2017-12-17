#include <iostream>
using namespace std;
int main(void)
{
	int a, b, c, d, p, m, n, pb, mb, nb;
	cin >> a >> b >> c >> d;
	cin >> p >> m >> n;
	pb = ((p % (a + b) > 0 && p % (a + b) <= a) ? 1 : 0) + ((p % (c + d) > 0 && p % (c + d) <= c) ? 1 : 0);
	mb = ((m % (a + b) > 0 && m % (a + b) <= a) ? 1 : 0) + ((m % (c + d) > 0 && m % (c + d) <= c) ? 1 : 0);
	nb = ((n % (a + b) > 0 && n % (a + b) <= a) ? 1 : 0) + ((n % (c + d) > 0 && n % (c + d) <= c) ? 1 : 0);
	cout << pb << '\n' << mb << '\n' << nb;
}
