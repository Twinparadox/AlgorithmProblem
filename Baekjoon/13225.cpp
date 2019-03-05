#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <vector>
using namespace std;
int divisor(int n)
{
	if (n == 1)
		return 1;

	int div = 1;
	map<int, int> prime;
	set<int> su;
	for (int i = 2; n > 1;)
	{
		if (n%i == 0)
		{
			prime[i]++;
			su.insert(i);
			n /= i;
		}
		else
		{
			i++;
		}
	}

	for (set<int>::iterator iter = su.begin(); iter != su.end(); iter++)
	{
		div *= (prime[*iter] + 1);
	}
	return div;
}
int main(void)
{
	int C;

	cin >> C;
	while (C--)
	{
		int n;
		cin >> n;
		cout << n << ' ' << divisor(n) << '\n';
	}
}