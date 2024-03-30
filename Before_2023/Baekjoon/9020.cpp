#include <iostream>
#include <math.h>
#include <set>
#include <vector>
using namespace std;
int main(void)
{
	int T, N;
	vector<bool> arr(10001, true);
	vector<int> sosu;
	cin >> T;
	for (int i = 2; i <= sqrt(10000); i++)
	{
		if (arr[i] == false)
			continue;
		for (int j = i + i; j <= 10000; j += i)
			arr[j] = false;
	}
	for (int i = 2; i <= 10000; i++)
		if (arr[i])
			sosu.push_back(i);

	int size = sosu.size();
	while (T--)
	{
		cin >> N;
		int tmp = 0, max = 10000, ans1, ans2;
		for (int i = 0; i < size; i++)
		{
			if (N - sosu[i] < 0)
				break;
			else if (arr[N - sosu[i]] && (N - sosu[i] * 2) >= 0)
			{
				if (max > (N - sosu[i] * 2))
				{
					max = N - sosu[i] * 2;
					ans1 = sosu[i];
					ans2 = N - sosu[i];
				}
			}
		}
		cout << ans1 << ' ' << ans2 << '\n';
	}
}