#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main(void)
{
	std::ios::sync_with_stdio(false);
	int maxSize = 1299710, T, k, primeSize;
	vector<int> arr(maxSize, 0);
	vector<int> prime;
	for (int i = 2; i <= maxSize; i++)
		arr[i] = i;

	for (int i = 2; i <= sqrt(maxSize); i++)
	{
		if (arr[i] == 0)
			continue;
		for (int j = i + i; j <= maxSize; j += i)
			arr[j] = 0;
	}
	for (int i = 2; i <= maxSize; i++)
		if (arr[i] != 0)
			prime.push_back(i);
	primeSize = prime.size();


	cin >> T;
	while (T--)
	{
		cin >> k;
		if (arr[k] != 0 || k == 1)
			cout << 0 << '\n';
		else
		{
			int start, end;
			for (int i = 0; i < primeSize; i++)
			{
				if (prime[i] > k)
				{
					start = prime[i - 1];
					end = prime[i];
					break;
				}
			}
			cout << end - start << '\n';
		}
	}
}