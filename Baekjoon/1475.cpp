#include <iostream>
#include <string.h>
using namespace std;
int main(void)
{
	char arr[8];
	int len, num[10] = { 0, }, max = 0;
	bool check = false;
	cin >> arr;
	len = strlen(arr);
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == '6' || arr[i] == '9')
			num[6]++;
		else
			num[arr[i] - '0']++;
	}
	if (num[6] % 2 == 1)
		num[6] = num[6] / 2 + 1;
	else
		num[6] = num[6] / 2;
	for (int i = 0; i < 10; i++)
		if (max < num[i])
			max = num[i];
	cout << max;
	return 0;
}
