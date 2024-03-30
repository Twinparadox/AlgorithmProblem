#include <algorithm>
#include <functional>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int main(void)
{
	int N, K;
	cin >> N >> K;
	vector<int> arr(N);
	vector<int> diff(N - 1);

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	int ans = arr[N - 1] - arr[0];

	for (int i = 0; i < N - 1; i++)
		diff[i] = arr[i + 1] - arr[i];
	sort(diff.begin(), diff.end(), greater<int>());

	for (int i = 0; i < N - 1 && --K; i++)
		ans -= diff[i];
	cout << ans;
}