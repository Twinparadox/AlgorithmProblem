#include <iostream>
#include <string.h>
using namespace std;
int main(void)
{
	char x[101], y[101], result[204], op;
	int len_x, len_y, i, len_max, len_min;
	for (i = 0; i < 200; i++)
		result[i] = '0';
	cin >> x;
	cin >> op;
	cin >> y;
	len_x = strlen(x);
	len_y = strlen(y);
	if (op == '+')
	{
		if (len_x > len_y)
		{
			len_min = len_y;
			len_max = len_x;
		}
		else if (len_x<len_y)
		{
			len_max = len_y;
			len_min = len_x;
		}
		else
		{
			len_max = len_x;
			len_min = len_x;
		}
		result[0] = '1';
		if (len_max == len_min)
			result[0] = '2';
		else
			result[len_max - len_min] = '1';
	}
	else if (op == '*')
	{
		len_max = len_x + len_y - 1;
		result[0] = '1';
	}
	for (i = 0; i < len_max; i++)
	{
		cout<<result[i];
	}
}
