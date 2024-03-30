#include <iostream>
using namespace std;
int main(void)
{
	int x, y;
	while (1)
	{
		cin >> x >> y;
		if (x == 0 && y == 0)
			break;
		cout << x / y << " " << x%y << " / " << y << "\n";
	}
}
