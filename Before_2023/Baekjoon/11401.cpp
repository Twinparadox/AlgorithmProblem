#include <iostream>
using namespace std;
const long long MOD = 1000000007;
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
	long long N, K;
	cin >> N >> K;

	long long a = fact(N);
	long long b = fact(K);
	long long c = fact(N - K);
	cout << ((a % MOD * power(b, MOD - 2)) % MOD) * power(c, MOD - 2) % MOD;
}