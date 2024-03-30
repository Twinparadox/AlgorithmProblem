#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	long long N, M, cnt = 0;

	cin >> N >> M;
	vector<long long> arr(N + 1, 0);
	vector<long long> prefix(N + 1, 0);
	vector<long long> counts(M + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];

		prefix[i] = (arr[i] % M + prefix[i - 1] % M) % M;

		if (prefix[i] == 0)
			cnt++;

		counts[prefix[i]]++;
	}

	for (int i = 0; i < M; i++)
		cnt += counts[i] * (counts[i] - 1) / 2;
	cout << cnt;
}