#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(false);
	int m, n, idx1, idx2;
	cin >> n >> m;
	vector<int> arr1(n), arr2(m), ans(n+m);
	for (int i = 0; i < n; i++)
		cin >> arr1[i];
	for (int i = 0; i < m; i++)
		cin >> arr2[i];

	idx1 = idx2 = 0;
	for (int i = 0; i < n + m; i++)
	{
		if (idx1 >= n)
			ans[i] = arr2[idx2++];
		else if (idx2 >= m)
			ans[i] = arr1[idx1++];
		else {
			if (arr1[idx1] < arr2[idx2])
				ans[i] = arr1[idx1++];
			else
				ans[i] = arr2[idx2++];
		}
	}
	for (int i = 0; i < n + m; i++)
		cout << ans[i] << ' ';
}
