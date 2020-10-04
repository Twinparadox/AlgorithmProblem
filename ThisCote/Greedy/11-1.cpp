#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int N, ans = 0, cnt;
	vector<int> arr;

	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());
	for (int i = 0; i < N; i++)
	{
		cnt++;
		if (arr[i] == cnt)
			ans++, cnt = 0;
	}

	cout << ans;
}