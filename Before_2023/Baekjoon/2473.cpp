#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M;
	long long ans = 3e9 + 1, res;
	long long cand1, cand2, cand3;

	cin >> N;
	vector<long long> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());
	int left, right;

	for (int i = 0; i < N; i++)
	{
		left = i + 1, right = N - 1;

		while (left < right)
		{
			long long sum = arr[i] + arr[left] + arr[right];

			if (abs(sum) < ans)
			{
				ans = abs(sum);
				res = sum;
				cand1 = arr[i], cand2 = arr[left], cand3 = arr[right];
			}
			if (sum == 0)
				break;
			else if (sum < 0)
				left++;
			else
				right--;
		}
	}
	cout << cand1 << ' ' << cand2 << ' ' << cand3;
}