#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
	int n, i = 1;
	double tmp;
	cin >> n;
	while (1)
	{
		if (n <= (int)pow(10, i))
			break;
		tmp = n / pow(10, i) + 0.5;
		n = (int)tmp * pow(10, i);
		i++;
	}
	cout << n;
}
