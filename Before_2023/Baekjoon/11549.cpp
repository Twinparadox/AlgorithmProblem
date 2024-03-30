#include <iostream>
using namespace std;
int main(void)
{
	int t, n, cnt = 0;
	cin >> t;
	for (int i = 0; i < 5; i++)
	{
		cin >> n;
		if (n == t)
			cnt++;
	}
	cout << cnt;
}
