#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MAX_DAY = 1000;
bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.second > b.second)
		return true;
	else if (a.second == b.second)
	{
		return a.first < b.first;
	}
	else
		return false;
}
int main(void)
{
	int N, ans = 0;

	cin >> N;
	vector<pair<int, int> > arr(N);
	vector<int> day(MAX_DAY + 1, 0);
	for (int i = 0; i < N; i++)
		cin >> arr[i].first >> arr[i].second;

	sort(arr.begin(), arr.end(), compare);

	for (int i = 0; i < N; i++)
	{
		if (!day[arr[i].first])
			day[arr[i].first] = arr[i].second;

		else
		{
			int d = arr[i].first;
			while (d >= 1)
			{
				if (day[d] == 0)
				{
					day[d] = arr[i].second;
					break;
				}

				d--;
			}
		}
	}

	for (int i = 1; i <= MAX_DAY; i++)
		ans += day[i];
	cout << ans;
}