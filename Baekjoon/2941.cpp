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
	{
		if (arr[i] == 'c' && (arr[i + 1] == '=' || arr[i + 1] == '-'))
			cnt++, i++;
		else if (arr[i] == 'd' && arr[i + 1] == 'z' && arr[i + 2] == '=')
			cnt++, i += 2;
		else if (arr[i] == 'd' && arr[i + 1] == '-')
			cnt++, i++;
		else if (arr[i] == 'l' && arr[i + 1] == 'j')
			cnt++, i++;
		else if (arr[i] == 'n' && arr[i + 1] == 'j')
			cnt++, i++;
		else if (arr[i] == 's' && arr[i + 1] == '=')
			cnt++, i++;
		else if (arr[i] == 'z' && arr[i + 1] == '=')
			cnt++, i++;
		else
			cnt++;
	}
	cout << cnt;
	return 0;
}
