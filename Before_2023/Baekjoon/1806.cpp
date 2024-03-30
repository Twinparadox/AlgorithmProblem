#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int sum = 0, len = 0, start = 0, end = 0;
	int N, S;
	cin >> N >> S;

	vector<int> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	while (1)
	{
		if (sum < S)
		{
			if (end == N)
				break;
			else
				sum += arr[end++];
		}
		else
		{
			int tmp = end - start;
			if (!len)
				len = tmp;
			else
				len = tmp < len ? tmp : len;
			sum -= arr[start++];
		}
	}

	cout << len;
}