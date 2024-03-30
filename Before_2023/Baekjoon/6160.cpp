#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct cow {
	int first;
	int second;
	int originIdx;
};
bool compare(const struct cow &a, const struct cow &b) {
	return a.first > b.first;
}
int main(void)
{
	int n, k, max, maxIdx;
	cin >> n >> k;
	vector<struct cow> arr(n);
	for (int i = 0, a, b; i < n; i++)
	{
		cin >> a >> b;
		arr[i].first = a;
		arr[i].second = b;
		arr[i].originIdx = i + 1;
	}
	sort(arr.begin(), arr.end(), compare);
	max = arr[0].second;
	maxIdx = arr[0].originIdx;
	for (int i = 0; i < k; i++)
	{
		if (max < arr[i].second)
			max = arr[i].second, maxIdx = arr[i].originIdx;
	}
	cout << maxIdx;
}