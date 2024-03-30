#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
using namespace std;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int K, N;
	map<long long, bool> check;
	priority_queue<long long, vector<long long>, greater<long long> > pq;

	cin >> K >> N;
	vector<long long> arr(K);
	long long maxVal = 0;

	for (int i = 0; i < K; i++)
	{
		cin >> arr[i];
		maxVal = maxVal < arr[i] ? arr[i] : maxVal;
		pq.push(arr[i]);
	}

	N -= 1;
	while (N != 0)
	{
		long long cur = pq.top();
		pq.pop();
		for (int i = 0; i < K; i++)
		{
			long long mul = cur * arr[i];
			if (pq.size() >= N && mul >= maxVal)
				continue;

			if (!check[mul])
			{
				check[mul] = true;
				pq.push(mul);
				maxVal = maxVal < mul ? mul : maxVal;
			}
		}
		N--;
	}

	cout << pq.top();
}