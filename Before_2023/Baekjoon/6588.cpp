#include <iostream>
#include <math.h>
#include <set>
#include <vector>
using namespace std;
int main(void)
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int size = 1000001;
	vector<int> arr(size, 0);
	vector<int> prime;
	for (int i = 2; i <= size; i++)
		arr[i] = i;
	for (int i = 2; i <= sqrt(size); i++)
	{
		if (arr[i] == 0)
			continue;
		for (int j = i + i; j <= size; j += i)
			arr[j] = 0;
	}
	for (int i = 3; i <= size; i += 2)
		if (arr[i])
			prime.push_back(i);

	size = prime.size();
	while (1)
	{
		int N;
		cin >> N;

		if (N == 0)
			break;

		int max = -1, ans1 = 0, ans2 = 0;
		for (int i = 0; i < size; i++)
		{
			if (prime[i] >= N)
				break;
			else if (N - prime[i] < prime[i])
				break;
			if (arr[prime[i]] && arr[N - prime[i]])
			{
				if (max < (N - prime[i] * 2))
				{
					max = N - prime[i] * 2;
					ans1 = prime[i];
					ans2 = N - prime[i];
				}
			}
		}

		if (max == -1)
			cout << "Goldbach's conjecture is wrong.\n";
		else
			cout << N << " = " << ans1 << " + " << ans2 << '\n';
	}
}