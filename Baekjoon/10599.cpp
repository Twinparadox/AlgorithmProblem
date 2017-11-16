#include <iostream>
using namespace std;
int main(void)
{
	int a, b, c, d, max, min;
	while (1)
	{
		cin >> a >> b >> c >> d;
		if (a == 0 && b == 0 && c == 0 && d == 0)
			break;
		max = d - a;
		min = c - b;
		cout << min << " " << max << "\n";
	}
}
