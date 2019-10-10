#include <iostream>
using namespace std;
long long N, k;
void solve(long long start, long long end)
{
	long long mid, res;
	while (start <= end)
	{
		long long cnt = 0;
		mid = (start + end) / 2;
		for (int i = 1; i <= N; i++)
			cnt += mid / i < N ? mid / i : N;
		if (cnt < k)
			start = mid + 1;
		else
			res = mid, end = mid - 1;
	}
	cout << res;
}
int main(void)
{
	cin >> N >> k;
	solve(1, k);
}