#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int len, dir;
	string* arr;
	cin >> len;
	arr = new string[len];
	for (int i = 0; i < len; i++)
		cin >> arr[i];
	cin >> dir;
	if (dir == 1)
	{
		for (int i = 0; i < len; i++)
			cout << arr[i] << '\n';
	}
	else if (dir == 2)
	{
		for (int i = 0; i < len; i++)
		{
			for (int j = len - 1; j >= 0; j--)
				cout << arr[i][j];
			cout << '\n';
		}
	}
	else
	{
		for (int i = len - 1; i >= 0; i--)
			cout << arr[i] << '\n';
	}
}
