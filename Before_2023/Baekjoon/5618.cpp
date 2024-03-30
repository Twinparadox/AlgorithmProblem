#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int euclid(int a, int b)
{
	return b ? euclid(b, a%b) : a;
}
int main(void)
{
	int n, a[3], gcd, arr[10000], size = 0;
	cin >> n;
	if (n == 2)
	{
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		gcd = euclid(a[1], a[0]);
	}
	else
	{
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		gcd = euclid(a[2], a[1]);
		if (gcd > a[0])
			gcd = euclid(gcd, a[0]);
		else
			gcd = euclid(a[0], gcd);
	}
	for (int i = 1; i <= sqrt(gcd); i++)
	{
		if (gcd%i == 0)
			arr[size++] = i;
	}
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\n";
	}
	for (int i = size - 1; i >= 0; i--)
	{
		if (gcd / arr[i] == arr[i])
			continue;
		cout << gcd / arr[i] << "\n";
	}
}
