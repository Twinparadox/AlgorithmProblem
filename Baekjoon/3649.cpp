#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
const int MM = 1e7;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n, x;

	while (cin >> x)
	{
		vector<int> arr;
		cin >> n;

		arr.resize(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		sort(arr.begin(), arr.end());
		int ans = 0;
		for (int i = 0; i < n - 1 && !ans; i++)
		{
			if (arr[i] <= x * MM)
			{
				if (binary_search(arr.begin(), arr.end(), x * MM - arr[i]))
				{
					if (arr[i] == x * MM - arr[i])
					{
						if (arr[i] == arr[i + 1])
						{
							ans = arr[i];
						}
					}
					else
					{
						ans = arr[i];
					}
				}
			}
		}

		if (ans)
			cout << "yes " << ans << ' ' << x * MM - ans;
		else
			cout << "danger";
		cout << '\n';
	}
}