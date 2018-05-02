#include <iostream>
#include <string.h>
using namespace std;
int main(void)
{
	char arr[1001];
	int len;
	cin >> arr;
	len = strlen(arr);
	for (int i = 0; i < len; i++)
	{
		if (arr[i] - 3 < 'A')
			cout << (char)(arr[i] + 23);
		else
			cout << (char)(arr[i] - 3);
	}
}
