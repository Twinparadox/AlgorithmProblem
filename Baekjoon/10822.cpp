#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;
int main(void)
{
	char arr[102];
	int len, sum = 0, tmp, s, size;
	cin >> arr;
	len = strlen(arr);
	arr[len] = ',';
	s = 0;
	for (int i = 0; i <= len; i++)
	{
		if (arr[i] == ',')
		{
			size = i - s - 1, tmp = 0;
			for (int j = 0; j < i - s; j++)
				tmp += (int)(arr[s + j] - '0')*pow(10, size - j);
			sum += tmp;
			s = i + 1;
		}
	}
	cout << sum;
}
