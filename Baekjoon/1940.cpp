#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
	int arr[15000], n, m, cnt = 0, i, j;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	i = 0, j = n - 1;
	while (arr[i] < arr[j] && i!=j)
	{
		if (arr[i] + arr[j] == m)
			cnt++, i++, j--;
		else if (arr[i] + arr[j] < m)
			i++;
		else
			j--;
	}
	cout << cnt;
}
