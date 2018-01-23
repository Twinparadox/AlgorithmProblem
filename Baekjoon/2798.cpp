#include <iostream>
using namespace std;
int main(void)
{
	int n, m, arr[100], ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n - 2; i++)
		for (int j = i + 1; j < n - 1; j++)
			for (int k = j + 1; k < n; k++)
				if (arr[i] + arr[j] + arr[k] <= m && m - (arr[i] + arr[j] + arr[k]) < m - ans)
					ans = arr[i] + arr[j] + arr[k];
	cout << ans;
}
