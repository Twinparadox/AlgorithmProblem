#include <iostream>
#include <string.h>
using namespace std;
char arr[1000001];
int capital[26] = { 0, };
int main(void)
{
	int cnt = 0, alen, cmax = 0, result;
	cin >> arr;
	alen = strlen(arr);
	for (int i = 0; i < alen; i++)
	{
		if (arr[i] >= 'A' && arr[i] <= 'Z')
			capital[(int)arr[i] - 65]++;
		else if (arr[i] >= 'a' && arr[i] <= 'z')
			capital[(int)arr[i] - 97]++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (capital[i] > cmax)
			cmax = capital[i];
	}
	for (int i = 0; i < 26; i++)
		if (cmax == capital[i])
			cnt++, result = i;
	if (cnt > 1)
		cout << "?";
	else
		cout << (char)(65 + result);
	return 0;
}
