#include <iostream>
#include <math.h>
using namespace std;
int count5(long long n)
{
	int cnt = 0;
	long long su = 1;
	for (long long i = 1;; i++)
	{
		su *= 5;
		if (n >= su)
			cnt += n / su;
		else
			break;
	}
	return cnt;
}
int count2(long long n)
{
	int cnt = 0;
	long long su = 1;
	for (long long i = 1;; i++)
	{
		su *= 2;
		if (n >= su)
			cnt += n / su;
		else
			break;
	}
	return cnt;
}
int main(void)
{
	int n, m, ans;
	int n5, n2, m5, m2, sub5, sub2;
	cin >> n >> m;
	n5 = count5(n);
	n2 = count2(n);
	m5 = count5(m);
	m2 = count2(m);
	sub5 = count5(n - m);
	sub2 = count2(n - m);

	int tmp1 = n2 - m2 - sub2;
	int tmp2 = n5 - m5 - sub5;
	ans = tmp1 < tmp2 ? tmp1 : tmp2;
	cout << ans;
}