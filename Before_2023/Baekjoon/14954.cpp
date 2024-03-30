#include <iostream>
#include <set>
using namespace std;
int main(void)
{
	int n, m;
	set<int> s;
	cin >> n;
	if (n == 1)
	{
		cout << "HAPPY";
		return 0;
	}
	while (1)
	{
		s.insert(n);
		m = 0;
		while (n >= 10)
		{
			int t = n % 10;
			n /= 10;
			m += t * t;
		}
		m += n * n;
		n = m;
		if (n == 1)
		{
			cout << "HAPPY";
			return 0;
		}
		else if (s.size() > 1 && s.find(n) != s.end())
		{
			cout << "UNHAPPY";
			return 0;
		}
	}
}
