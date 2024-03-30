#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.first < b.first)
		return true;
	else
		return false;
}
int main(void)
{
	int t, N;
	cin >> t;
	while (t--)
	{
		cin >> N;
		vector<pair<int, int> > arr(N);
		for (int i = 0; i < N; i++)
			cin >> arr[i].first >> arr[i].second;

		sort(arr.begin(), arr.end(), compare);

		int cur = arr[0].second, ans = 1;
		for (int i = 1; i < N; i++)
			if (arr[i].second < cur)
				ans++, cur = arr[i].second;

		cout << ans << '\n';
	}
}