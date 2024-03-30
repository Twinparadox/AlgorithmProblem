#include <iostream>
using namespace std;
int main(void)
{
	int cows[80000], n, cn = 0;
	long long sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int h;
		cin >> h;
		while (cn > 0 && cows[cn - 1] <= h) cn--;
		sum += cn;
		cows[cn++] = h;
	}
	cout << sum;
}
