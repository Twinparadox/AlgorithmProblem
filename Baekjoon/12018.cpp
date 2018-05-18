#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	int n, m, min[100] = { 0, }, sum = 0, cnt;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int p, l;
		cin >> p >> l;
		vector<int> arr(p);
		for (int j = 0; j < p; j++)
			cin >> arr[j];
		sort(arr.begin(), arr.end());

		if (p >= l)
			min[i] = arr[p - l];
		else
			min[i] = 1;
	}
	sort(min, min + n);
	for (cnt = 0; cnt < n; cnt++)
	{
		if (sum + min[cnt] > m)
			break;
		sum += min[cnt];
	}
	cout << cnt;
}
