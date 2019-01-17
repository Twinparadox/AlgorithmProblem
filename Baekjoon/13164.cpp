#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	int n, k, sum = 0;
	cin >> n >> k;
	vector<int> arr(n);
	vector<int> sub(n - 1);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n - 1; i++)
		sub[i] = arr[i + 1] - arr[i];
	sort(sub.begin(), sub.end());

	for (int i = 0; i < n - k; i++)
		sum += sub[i];
	cout << sum;
}