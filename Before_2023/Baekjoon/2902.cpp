#include <iostream>
#include <string.h>
using namespace std;
int main(void)
{
	char arr[101];
	int len;
	cin >> arr;
	len = strlen(arr);
	cout << arr[0];
	for (int i = 1; i < len; i++)
		if (arr[i - 1] == '-' && arr[i] != '-')
			cout << arr[i];
}
