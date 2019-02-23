#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int N, tmp;
	cin >> N;

	vector<int> arr(20);
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		for (int j = 0; tmp; j++)
		{
			if (tmp % 2)
				arr[j]++;
			tmp /= 2;
		}
	}

	long long ans = 0;
	for (int j = 0; j < 20; j++)
		ans += (long long)(N - arr[j])*arr[j] * (1 << j);

	cout << ans;
}