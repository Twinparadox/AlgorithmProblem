#include <iostream>
#include <algorithm>
using namespace std;
int arr[100000];
int main(void)
{
	int n, max = 0, weight;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	for (int i = n - 1; i >= 0; i--)
	{
		weight = arr[i] * (n - i);
		max = max < weight ? weight : max;
	}
	cout << max;
}
