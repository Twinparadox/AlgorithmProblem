#include <iostream>
using namespace std;
int main(void)
{
	int t, n, sum = 0;
	cin >> t;
	while (t--)
	{
		cin >> n;
		sum += n;
		cout << sum << '\n';
	}
}