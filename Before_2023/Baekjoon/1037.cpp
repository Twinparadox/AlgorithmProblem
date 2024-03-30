#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
	int n;
	long long arr[50], result;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	result = arr[0] * arr[n - 1];
	cout << result;
}
