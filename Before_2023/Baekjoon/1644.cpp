#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int main(void)
{
	std::ios::sync_with_stdio(false);
	int n;
	vector<int> sosu;

	cin >> n;
	vector<int> arr(n + 1, 0);
	for (int i = 2; i <= n; i++)
		arr[i] = i;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (arr[i] == 0)
			continue;
		for (int j = i + i; j <= n; j += i)
			arr[j] = 0;
	}
	for (int i = 2; i <= n; i++)
		if (arr[i] != 0)
			sosu.push_back(arr[i]);

	int cnt = 0, size = sosu.size();
	for (int i = 0; i < size; i++)
	{
		int tmp = 0;
		for (int j = i; j < size; j++)
		{
			tmp += sosu[j];
			if (tmp == n)
			{
				cnt++;
				break;
			}
			else if (tmp > n)
			{
				break;
			}
		}
	}

	cout << cnt;
}