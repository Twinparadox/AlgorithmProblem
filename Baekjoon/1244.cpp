#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int N, T;
	cin >> N;
	vector<int> arr(N, 0);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int g, num;
		vector<int> change(N, 0);

		cin >> g >> num;
		if (g == 1)
		{
			for (int i = num - 1; i < N; i += num)
				change[i]++;
		}
		else
		{
			int center = num - 1;
			int left, right;
			left = right = center;
			while (left >= 0 && right <= N - 1)
			{
				if (arr[left] != arr[right])
					break;
				else
					left--, right++;
			}
			for (int i = left + 1; i <= right - 1; i++)
				change[i]++;
		}

		for (int i = 0; i < N; i++)
			if (change[i] % 2 == 1)
				arr[i] = 1 - arr[i];
	}

	for (int i = 0; i < N; i++)
	{
		if (i != 0 && i % 20 == 0)
			cout << '\n';
		cout << arr[i] << ' ';
	}
}