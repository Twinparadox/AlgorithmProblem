#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;
vector<int> lis;
int lower_bounds(int start, int end, int target)
{
	while (start < end)
	{
		int mid = (start + end) / 2;
		if (lis[mid] < target)
			start = mid + 1;
		else
			end = mid;
	}
	return end + 1;
}
int main(void)
{
	int N, max = 0;

	cin >> N;
	arr.resize(N + 1, 0);
	lis.resize(N + 1, 0);
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	int i = 1, ans = 1;
	lis[1] = arr[1];
	i++;
	for (; i <= N; i++)
	{
		if (lis[ans] < arr[i])
		{
			lis[ans + 1] = arr[i];
			ans++;
		}
		else
		{
			int idx = lower_bounds(0, ans, arr[i]);
			lis[idx - 1] = arr[i];
		}
	}

	cout << ans;
}