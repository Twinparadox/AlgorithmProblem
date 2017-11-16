#include <iostream>
#include <string.h>
using namespace std;
int main(void)
{
	char arr[101];
	int len, cnt = 0;
	cin >> arr;
	len = strlen(arr);
	for (int i = 0; i < len; i++)
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
			cnt++;
	cout << cnt;
}
