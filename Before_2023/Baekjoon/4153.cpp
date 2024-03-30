#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int main(void)
{
	int a[3];
	while (1)
	{
		for (int i = 0; i < 3; i++)
			cin >> a[i];
		if (a[0] == 0 && a[1] == 0 && a[2] == 0)
			break;
		sort(a, a + 3);
		if ((int)pow(a[2], 2) == ((int)pow(a[0], 2) + (int)pow(a[1], 2)))
			cout << "right\n";
		else
			cout << "wrong\n";
	}
}
