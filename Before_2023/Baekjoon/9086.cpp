#include <iostream>
#include <string.h>
using namespace std;
int main(void)
{
	int n, len;
	cin >> n;
	while (n--)
	{
		char arr[1001];
		cin >> arr;
		len = strlen(arr);
		cout << arr[0] << arr[len - 1] << endl;
	}
}