#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct person {
	int weight;
	int height;
	int bigger;
	int originIdx;
};
int compareBigger(const struct person a, const struct person b)
{
	return a.bigger < b.bigger;
}
int compareIdx(const struct person a, const struct person b)
{
	return a.originIdx < b.originIdx;
}
int main(void)
{
	int n;
	cin >> n;
	vector<struct person> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].weight >> arr[i].height;
		arr[i].originIdx = i;
		arr[i].bigger = 0;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (arr[i].weight > arr[j].weight && arr[i].height > arr[j].height)
				arr[j].bigger++;

	sort(arr.begin(), arr.end(), compareIdx);
	for (int i = 0; i < n; i++)
		cout << arr[i].bigger + 1 << ' ';
}