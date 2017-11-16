#include <iostream>
#include <string.h>
using namespace std;
int main(void)
{
	int t;
	cin >> t;
	while (t)
	{
		char arr[11];
		int cnt = 0, len, digit[10] = { 0, };
		cin >> arr;
		len = strlen(arr);
		for (int i = 0; i < len; i++)
			digit[arr[i] - '0']++;
		for (int i = 0; i < 10; i++)
			if (digit[i] != 0)
				cnt++;
		cout << cnt << "\n";
		t--;
	}
}
