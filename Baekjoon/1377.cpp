#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
	if (a.first < b.first)
		return true;
	else if (a.first == b.first)
	{
		return a.second < b.second;
	}
	else
		return false;
}
int main(void)
{
	int n;
	cin >> n;
	vector<pair<int, int> > arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr.begin(), arr.end(), compare);

	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (cnt < arr[i].second - i)
			cnt = arr[i].second - i;

	cout << cnt + 1;
}