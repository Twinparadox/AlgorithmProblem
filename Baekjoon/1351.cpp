#include <map>
#include <iostream>
using namespace std;

map<long long, long long> dp;
long long recursive(long long N, long long& P, long long& Q)
{
	if (N == 0)
		return 1;
	else if (dp[N])
		return dp[N];

	return dp[N] = recursive(N / P, P, Q) + recursive(N / Q, P, Q);
}
int main(void)
{
	long long N, P, Q;

	cin >> N >> P >> Q;

	cout << recursive(N, P, Q);
}