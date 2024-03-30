#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int n, k, sum = 0, ans;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < k; i++)
		sum += arr[i];

	ans = sum;
	for (int i = 0; i + k < n; i++)
	{
		sum += arr[i + k];
		sum -= arr[i];
		if (sum > ans)
			ans = sum;
	}
	cout << ans;
}
