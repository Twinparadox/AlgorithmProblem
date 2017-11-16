#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
	int k, t;
	cin >> t;
	while (t--)
	{
		cin >> k;
		cout << (int)pow(2, k) - 1 << "\n";
	}
}
