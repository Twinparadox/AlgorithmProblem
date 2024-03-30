#include <iostream>
#include <cstring>
using namespace std;
int main(void)
{
	char arr[21];
	int len, sum = 0, check = 1;
	cin >> arr;
	len = strlen(arr);
	for (int i = 0; i < len; i++)
	{
		if (arr[i] >= 'a' && arr[i] <= 'z')
			sum += (int)(arr[i] - 'a' + 1);
		else if (arr[i] >= 'A' && arr[i] <= 'Z')
			sum += (int)(arr[i] - 'A' + 27);
	}
	for (int i = 2; i <= sum; i++)
	{
		if (sum%i == 0)
			check++;
		if (check >= 3)
			break;
	}
	if (check < 3)
		cout << "It is a prime word.";
	else
		cout << "It is not a prime word.";
}
