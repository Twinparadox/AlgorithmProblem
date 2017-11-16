#include <iostream>
#include <string.h>
using namespace std;
char arr[1000001];
int main(void)
{
	int n, size;
	cin >> n;
	cin >> arr;
	for (int i = n - 1; i >= 1; i--)
	{
		if (arr[i] == 'A')
		{
			if (arr[i - 1] == 'A' || arr[i - 1] == 'C')
				arr[i - 1] = 'A';
			else if (arr[i - 1] == 'G')
				arr[i - 1] = 'C';
			else
				arr[i - 1] = 'G';
		}
		else if (arr[i] == 'T')
		{
			if (arr[i - 1] == 'A' || arr[i - 1] == 'C')
				arr[i - 1] = 'G';
			else if (arr[i - 1] == 'G')
				arr[i - 1] = 'A';
			else
				arr[i - 1] = 'T';
		}
		else if (arr[i] == 'G')
		{
			if (arr[i - 1] == 'A')
				arr[i - 1] = 'C';
			else if (arr[i - 1] == 'G')
				arr[i - 1] = 'G';
			else if (arr[i - 1] == 'C')
				arr[i - 1] = 'T';
			else
				arr[i - 1] = 'A';
		}
		else
		{
			if (arr[i - 1] == 'A')
				arr[i - 1] = 'A';
			else if (arr[i - 1] == 'G')
				arr[i - 1] = 'T';
			else if (arr[i - 1] == 'C')
				arr[i - 1] = 'C';
			else
				arr[i - 1] = 'G';
		}
	}
	cout << arr[0];
}
