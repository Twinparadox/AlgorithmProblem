#include <iostream>
using namespace std;
int main(void)
{
	int n, tmp, cnt = 0, start = 0;
	cin >> n;
	tmp = n;
	while (tmp > 0)
	{
		if (tmp >= 10)
			start++, tmp /= 10;
		else
			start++, tmp=0;
	}
	if (n - start > 0)
		start = n - start * 9;
	else
		start = 0;
	for (int i = start - 1, tmps; i <= n; i++)
	{
		tmp = i, tmps = 0;
		while (tmp > 0)
		{
			if (tmp >= 10)
				tmps += tmp % 10, tmp /= 10;
			else
				tmps += tmp, tmp = 0;
		}
		if (n == tmps + i)
		{
			cout << i;
			return 0;
		}
	}
	cout << 0;
}
