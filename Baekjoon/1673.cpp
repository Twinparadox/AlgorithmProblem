#include <iostream>
using namespace std;
int main(void)
{
	int n, k;
	int chicken = 0;
	while (cin >> n >> k)
	{
		chicken = n;
		while (n >= k)
		{
			chicken += n / k;
			n = n / k + n%k;
		}
		cout << chicken << endl;
	}
	return 0;
}
