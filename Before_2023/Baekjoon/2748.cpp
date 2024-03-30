#include <iostream>
using namespace std;
int main(void)
{
	long long arr[100];
	int n;
	arr[0] = 0, arr[1] = 1;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	cout << arr[n];
}
