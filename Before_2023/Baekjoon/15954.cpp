#include <iostream>
#include <limits>
#include <vector>
#include <math.h>
using namespace std;
int main(void)
{
	int n, k, s, e;
	double ans = std::numeric_limits<int>::max();
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (s = 0; s <= n - k; s++)
	{
		for (e = k - 1 + s; e < n; e++)
		{
			double tmpSum = 0.0, aver, standard;
			for (int i = s; i <= e; i++)
				tmpSum += arr[i];
			aver = tmpSum / (e - s + 1);

			tmpSum = 0.0;
			for (int i = s; i <= e; i++)
				tmpSum += (arr[i] - aver)*(arr[i] - aver);
			standard = sqrt(tmpSum / (e - s + 1));

			if (ans > standard)
				ans = standard;
		}
	}
	cout.precision(6);
	cout << fixed << ans;
}
