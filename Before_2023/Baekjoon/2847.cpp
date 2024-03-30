#include <iostream>
using namespace std;
int main(void)
{
	int n, arr[100], cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = n - 1; i > 0; i--)
		if (arr[i] <= arr[i - 1])
			cnt += (arr[i - 1] - arr[i] + 1), arr[i - 1] = arr[i] - 1;
	cout << cnt;
}
