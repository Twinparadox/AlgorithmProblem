#include <iostream>
#include <string.h>
using namespace std;
int main(void)
{
	char arr[333335];
	int n, len, tmp, cnt;
	cin >> arr;
	len = strlen(arr);

	n = arr[0] - '0';
	tmp = n, cnt = 0;
	int list[3] = { 0, };
	while (tmp > 0)
	{
		if (tmp >= 2)
			list[cnt++] = tmp % 2, tmp /= 2;
		else
			list[cnt++] = tmp, tmp = 0;
	}
	if (list[2] == 0)
	{
		if (list[1] == 0)
			cout << list[0];
		else if (list[1] == 1)
			cout << list[1] << list[0];
	}
	else
	{
		for (int i = 2; i >= 0; i--)
			cout << list[i];
	}

	for (int i = 1; i < len; i++)
	{
		n = arr[i] - '0';
		tmp = n, cnt = 0;
		int list[3] = { 0, };
		while (tmp > 0)
		{
			if (tmp >= 2)
				list[cnt++] = tmp % 2, tmp /= 2;
			else
				list[cnt++] = tmp, tmp = 0;
		}
		for (int i = 2; i >= 0; i--)
			cout << list[i];
	}
}
