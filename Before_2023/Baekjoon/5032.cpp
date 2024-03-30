#include <iostream>
using namespace std;
int main(void)
{
	int e, f, c, s, sum = 0;
	cin >> e >> f >> c;
	s = e + f;
	while (1)
	{
		if (s < c)
			break;
		sum += s / c;
		s = s%c + s / c;
	}
	cout << sum;
}
