#include <iostream>
using namespace std;
int main(void)
{
	int t, d, n, s, p;
	cin >> t;
	while (t--)
	{
		cin >> d >> n >> s >> p;
		if (d + n*p == n*s)
			cout << "does not matter\n";
		else if (d + n*p < n*s)
			cout << "parallelize\n";
		else
			cout << "do not parallelize\n";
	}
}
