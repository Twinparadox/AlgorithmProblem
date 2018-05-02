#include <iostream>
using namespace std;
int main(void)
{
	int t, n, tmp, sum = 0;
	cin >> t;
	while (t--)
	{
		sum = 0;
		cin >> n;
		while (n--)
		{
			cin >> tmp;
			sum += tmp;
		}
		cout << sum << "\n";
	}
}
