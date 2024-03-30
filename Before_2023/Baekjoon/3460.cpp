#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int main(void)
{
	int t, n;
	cin >> t;
	while (t--)
	{
		int i = 19, arr[20], cnt = 0;
		cin >> n;
		while (n > 0)
		{
			if (pow(2, i) <= n)
				n -= pow(2, i), arr[cnt++] = i;
			i--;
		}
		sort(arr, arr + cnt);
		for (int i = 0; i < cnt; i++)
			cout << arr[i] << ' ';
		cout << '\n';
	}
}
