#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int N, M, ans = 0;
	vector<int> arr, get;

	cin >> N >> M;
	arr.resize(N + 1);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());

	int idx = 0;
	for (int i = 0; i <= N; i++)
	{
		if (arr[i] == 0 && !idx)
		{
			idx = i;
			break;
		}
	}

	for (int i = 0; i < idx; i += M)
		ans += abs(arr[i] * 2);
	for (int i = N; i > idx; i -= M)
		ans += arr[i] * 2;

	ans -= max(abs(arr[0]), abs(arr[N]));
	cout << ans;
}