#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;
vector<long long> arr;
long long cutting(long long size)
{
	long long cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += arr[i] / size;
	return cnt;
}
int main(void)
{
	long long max = 0, min = 2147483647, ans = 0, mid, cnt;
	cin >> n >> k;
	arr.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (max < arr[i])
			max = arr[i];
	}
	min = 1;
	while (max >= min)
	{
		mid = (max + min) / 2;
		cnt = cutting(mid);
		if (cnt < k)
			max = mid - 1;
		else
		{
			min = mid + 1;
			if (mid > ans)
				ans = mid;
		}
	}
	cout << ans;
}