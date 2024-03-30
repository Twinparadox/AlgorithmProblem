#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	int n, c, start = 1, mid, end, cnt = 0, ans = 1;
	cin >> n >> c;
	vector<int> coord(n);
	for (int i = 0; i < n; i++)
		cin >> coord[i];

	sort(coord.begin(), coord.end());
	end = coord[n - 1] - coord[0];
	while (1)
	{
		mid = (start + end) / 2;
		cnt = 1;
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (coord[i] + mid > coord[j])
					continue;
				else
				{
					i = j - 1;
					cnt++;
					break;
				}
			}
		}
		if (start > end)
			break;
		if (cnt >= c)
			ans = mid, start = mid + 1;
		else
			end = mid - 1;
	}
	cout << ans;
}