#include <iostream>
using namespace std;
int main(void)
{
	int t, n, m, x, y;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		x = m;
		y = n - x, x -= y;
		cout << x << " " << y << "\n";
	}
}
