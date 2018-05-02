#include <iostream>
#include <string.h>
using namespace std;
int main(void)
{
	char arr[101];
	int len;
	cin >> arr;
	len = strlen(arr);
	for (int i = 0; i < len; i++)
	{
		if (arr[i] >= 'A' && arr[i] <= 'Z')
			cout << (char)(arr[i] + 32);
		else if (arr[i] >= 'a' && arr[i] <= 'z')
			cout << (char)(arr[i] - 32);
	}
}
