#include <iostream>
using namespace std;
int main(void)
{
	double x, y;
	cout << fixed;
	cout.precision(2);
	while (1)
	{
		cin >> x;
		if (x < 0)
			break;

		y = x * 0.167;
		cout << "Objects weighing " << x << " on Earth will weigh " << y << " on the moon.\n";
	}
}