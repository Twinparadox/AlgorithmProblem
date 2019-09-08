#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, ans = 0;
	vector<int> arr;

	cin >> N;
	arr.resize(N);

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	int idx;
	for (idx = N - 1; idx >= 2; idx -= 3)
		ans += arr[idx] + arr[idx - 1];
	for (int i = 0; i <= idx; i++)
		ans += arr[i];

	cout << ans;
}