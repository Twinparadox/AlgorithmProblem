#include <iostream>
#include <string.h>
using namespace std;
int main(void)
{
	int len;
	char arr[101];
	cin >> arr;
	len = strlen(arr);
	for (int i = 0; i < len; i++)
		if (!(arr[i] == 'C' || arr[i] == 'A' || arr[i] == 'M' || arr[i] == 'B' || arr[i] == 'R' || arr[i] == 'I' || arr[i] == 'D' || arr[i] == 'G' || arr[i] == 'E'))
			cout << arr[i];
}
