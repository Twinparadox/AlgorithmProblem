#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M, L;
	cin >> N >> M >> L;
	vector<int> arr(N + 2);
	arr[0] = 0, arr[N + 1] = L;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());
	int right = L, left = 0, ans = L;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int cnt = 0;

		int size = arr.size();
		for (int i = 1; i < size; i++)
			cnt += (arr[i] - arr[i - 1] - 1) / mid;

		if (cnt > M)
			left = mid + 1;
		else
		{
			ans = min(ans, mid);
			right = mid - 1;
		}
	}
	cout << ans;
}