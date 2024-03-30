#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
	int arr[3];
	char list[4];
	for (int i = 0; i < 3; i++)
		cin >> arr[i];
	cin >> list;
	sort(arr, arr + 3);
	for (int i = 0; i < 3; i++)
	{
		switch(list[i])
		{
		case 'A':
			cout << arr[0] << ' ';
			break;
		case 'B':
			cout << arr[1] << ' ';
			break;
		case 'C':
			cout << arr[2] << ' ';
			break;
		default:
			break;
		}
	}
}
