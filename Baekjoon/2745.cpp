#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int main(void)
{
	char arr[100];
	int len, sum = 0, n;
	cin >> arr;
	len = strlen(arr);
	cin >> n;
	for (int i = len - 1; i >= 0; i--)
	{
		if (arr[i] >= '0' && arr[i] <= '9')
			sum += pow(n, len - 1 - i)*(int)(arr[i] - '0');
		else
			sum += pow(n, len - 1 - i)*(int)(arr[i] - 'A' + 10);
	}
	cout << sum;
}
