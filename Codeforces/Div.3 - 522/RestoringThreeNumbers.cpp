#include <iostream>
using namespace std;
int main(void)
{
	int arr[4];
	int abc = 0;
	int a, b, c;
	for (int i = 0; i < 4; i++)
	{
		cin >> arr[i];
		if (arr[i] > abc)
			abc = arr[i];
	}

	for (int i = 0; i < 4; i++)
		if (abc != arr[i])
			cout << abc - arr[i] << ' ';
}