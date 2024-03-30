#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main(void)
{
	int n, m, arr[1001], max = -1, price;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> arr[i];

	sort(arr + 1, arr + 1 + m, greater<int>());
	for (int i = 1; i <= n; i++)
		if (i*arr[i] > max)
			max = arr[i] * i, price = arr[i];
	
	cout << price << ' ' << max;
}
