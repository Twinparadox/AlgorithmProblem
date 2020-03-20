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
	int ans = 2e9 + 1;

	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int left, right;
	left = 0, right = N - 1;

	int cand1, cand2;
	while (left < right)
	{
		int sum = arr[left] + arr[right];
		if (sum == 0)
		{
			cand1 = arr[left], cand2 = arr[right];
			break;
		}

		if (abs(sum) < ans)
		{
			ans = abs(sum);
			cand1 = arr[left], cand2 = arr[right];
		}
		if (sum < 0)
			left++;
		else
			right--;
	}
	cout << cand1 << ' ' << cand2;
}