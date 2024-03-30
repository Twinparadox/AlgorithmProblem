#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int main(void)
{
	int N;
	long long ans = 0;

	cin >> N;
	vector<pair<long long, long long> > arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i].first >> arr[i].second;
	arr.push_back(make_pair(arr[0].first, arr[0].second));

	for (int i = 0; i < N; i++)
	{
		ans += arr[i].second * arr[i + 1].first;
		ans -= arr[i].first * arr[i + 1].second;
	}

	ans = abs(ans);
	cout << ans / 2 << '.';
	if (ans % 2 == 0)
		cout << 0;
	else
		cout << 5;
}