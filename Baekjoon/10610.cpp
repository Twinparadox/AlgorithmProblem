#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main(void)
{
	char arr[100001];
	int cnt = 0, len, tmp, sum = 0;
	cin >> arr;
	len = strlen(arr);
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == '0')
			cnt++;
		else
			sum += (int)(char)(arr[i] - '0');
	}
	if (cnt == 0)
		cout << -1;
	else
	{
		if (sum % 3 == 0)
		{
			sort(arr, arr + len);
			for (int i = len - 1; i >= 0; i--)
				cout << arr[i];
		}
		else
			cout << -1;
	}
}
