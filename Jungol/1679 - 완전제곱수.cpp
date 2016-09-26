#include <iostream>
#include <math.h>
using namespace std;

int main(void)
{
	int m, n;
	int min = 0;
	int sum = 0, cnt = 0;
	int i;
	cin >> m >> n;
	for (i = sqrt(m) + 1; i <= sqrt(n); i++)
	{
		if (cnt == 0)
			min = i;

		cnt++;
		sum += pow(i, 2);
	}
	if (cnt != 0)
		cout << sum << endl << pow(min, 2);
	else
		cout << -1;
}