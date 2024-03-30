#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
	int n, su = 1;
	long long cnt = 0;
	cin >> n;

	while (pow(10, su) <= n)
	{
		cnt += su * (pow(10, su) - pow(10, su - 1));
		su++;
	}
	if (pow(10, su) - n >= 0)
		cnt += su * (n - pow(10, su - 1) + 1);
	cout << cnt;
}
