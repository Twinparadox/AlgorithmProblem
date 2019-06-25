#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> arr;
int ans1 = -1, ans2 = -1, ans = 2100000000;
void binary(int left, int right)
{
	if (left >= right)
		return;

	int sum = arr[left] + arr[right];
	if (abs(sum) < ans)
	{
		ans = abs(sum);
		ans1 = left;
		ans2 = right;
		if (ans == 0)
			return;
	}
	if (sum < 0)
		binary(left + 1, right);
	else
		binary(left, right - 1);
}
int main(void)
{
	cin >> N;

	arr = vector<int>(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());

	binary(0, N - 1);
	cout << arr[ans1] << ' ' << arr[ans2];
}