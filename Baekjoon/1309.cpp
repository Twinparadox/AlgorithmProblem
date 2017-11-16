#include <iostream>
using namespace std;
int main(void)
{
	int arr[100001] = { 1, 3, }, n;
	cin >> n;
	for (int i = 2; i <= n; i++)
		arr[i] = (arr[i - 1] * 2 + arr[i - 2]) % 9901;
	cout << arr[n];
}

