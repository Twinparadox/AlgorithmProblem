#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9 + 7;
long long power(long long x, long long n)
{
	long long ans = 1;
	while (n > 0)
	{
		if (n % 2 == 1)
			ans = (ans * x) % MOD;
		x = (x * x) % MOD;
		n /= 2;
	}
	return ans;
}
long long fact(long long n)
{
	long long ans = 1;
	for (long long i = 2; i <= n; i++)
		ans = (ans * i) % MOD;
	return ans;
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	long long N, K, T;
	vector<long long> arr(4e6 + 1);
	cin >> T;

	arr[0] = arr[1] = 1;
	for (long long i = 2; i <= 4e6; i++)
		arr[i] = (arr[i - 1] * i) % MOD;
	while (T--)
	{
		cin >> N >> K;

		long long a = arr[N];
		long long b = arr[K];
		long long c = arr[N - K];
		cout << ((a % MOD * power(b, MOD - 2)) % MOD)*power(c, MOD - 2) % MOD << '\n';
	}
}