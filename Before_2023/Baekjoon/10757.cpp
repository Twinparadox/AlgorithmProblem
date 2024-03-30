#include <iostream>
#include <string.h>
using namespace std;
int main(void)
{
	char a[10001], b[10001];
	int c[10002] = { 10, }, max, alen, blen, i, j, k, tmp;
	cin >> a >> b;
	alen = strlen(a), blen = strlen(b);
	max = alen < blen ? blen : alen;
	i = alen - 1, j = blen - 1, k = max, tmp = 0;
	while (i >= 0 && j >= 0)
	{
		if ((a[i] - '0') + (b[j] - '0') + tmp >= 10)
		{
			c[k--] = ((a[i--] - '0') + (b[j--] - '0') + tmp) % 10;
			tmp = 1;
		}
		else
		{
			c[k--] = (a[i--] - '0') + (b[j--] - '0') + tmp;
			tmp = 0;
		}
	}
	if (i >= 0 || j >= 0)
	{
		while (i >= 0)
		{
			if (a[i] - '0' + tmp >= 10)
			{
				c[k--] = (a[i--] - '0' + tmp) % 10;
				tmp = 1;
			}
			else
			{
				c[k--] = (a[i--] - '0' + tmp);
				tmp = 0;
			}
		}
		while (j >= 0)
		{
			if (b[j] - '0' + tmp >= 10)
			{
				c[k--] = (b[j--] - '0' + tmp) % 10;
				tmp = 1;
			}
			else
			{
				c[k--] = (b[j--] - '0' + tmp);
				tmp = 0;
			}
		}
	}
	else if(tmp > 0)
	{
		c[k] = tmp;
	}
	if (tmp > 0)
	{
		c[k] = tmp;
	}
	for (int i = 0; i <= max; i++)
	{
		if (c[i] >= 10)
			continue;
		else
			cout << c[i];
	}
}
