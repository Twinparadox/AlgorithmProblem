#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct ball
{
	int num;
	int color;
	int size;
	int sum;
};
bool compareNum(const struct ball& a, const struct ball& b)
{
	return a.num < b.num;
}
bool compareSize(const struct ball& a, const struct ball& b)
{
	return a.size < b.size;
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int total = 0;
	int n;
	cin >> n;
	vector<struct ball> arr(n);
	vector<int> sumArr(n + 1, 0);
	vector<int> ans(n + 1, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].color >> arr[i].size;
		arr[i].num = i;
	}
	sort(arr.begin(), arr.end(), compareSize);

	for (int i = 0, j = 0; i < n; i++)
	{
		for (; arr[i].size > arr[j].size; j++)
		{
			total += arr[j].size;
			sumArr[arr[j].color] += arr[j].size;
		}
		ans[arr[i].num] = total - sumArr[arr[i].color];
	}

	sort(arr.begin(), arr.end(), compareNum);
	for (int i = 0; i < n; i++)
		cout << ans[i] << "\n";
}