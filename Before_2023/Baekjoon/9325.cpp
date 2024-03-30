#include <iostream>
using namespace std;
int main(void)
{
	int t, s, n, q, p;
	int sum;
	cin >> t;
	while (t--)
	{
		cin >> s >> n;
		sum = s;
		for (int i = 0; i < n; i++)
		{
			cin >> q >> p;
			sum += q*p;
		}
		cout << sum << "\n";
	}
}
