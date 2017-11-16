#include <iostream>
#include <string.h>
using namespace std;
int main(void)
{
	int t, a, b, len;
	cin >> t;
	while (t--)
	{
		char arr[1000001];
		cin >> a >> b;
		cin >> arr;
		len = strlen(arr);
		for (int i = 0; i < len; i++)
		{
			cout << (char)((((arr[i] - 65)*a + b) % 26) + 65);
		}
		cout << "\n";
	}
}
