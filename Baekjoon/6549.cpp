#include <iostream>
#include <vector>
using namespace std;
long long solve(vector<long long>& arr, long long left, long long right)
{
	if (left == right)
		return arr[left];

	long long mid = (left + right) / 2;
	long long w1 = solve(arr, left, mid);
	long long w2 = solve(arr, mid + 1, right);
	
	long long ans = w1 < w2 ? w2 : w1;
	long long l = mid, r = mid + 1;
	long long  h1 = arr[l], h2 = arr[r], h;

	h = h1 < h2 ? h1 : h2;

	if (ans < h * 2)
		ans = h * 2;

	while (left < l || r < right)
	{
		if (left < l && (r == right || arr[l - 1] > arr[r + 1]))
		{
			l--;
			h = h < arr[l] ? h : arr[l];
		}
		else
		{
			r++;
			h = h < arr[r] ? h : arr[r];
		}

		long long tmp = h * (r - l + 1);
		ans = ans < tmp ? tmp : ans;
	}
	return ans;
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	while (1)
	{
		cin >> N;
		if (N == 0)
			break;

		vector<long long> arr(N);
		for (int i = 0; i < N; i++)
			cin >> arr[i];
		cout << solve(arr, 0, N - 1) << '\n';
	}
}