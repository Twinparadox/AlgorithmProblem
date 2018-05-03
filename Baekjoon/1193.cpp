#include <iostream>
using namespace std;
int main(void)
{
	int n, k = 1;
	cin >> n;
	while (1)
	{
		if (k*(k + 1) / 2 == n)
		{
			if (k % 2 == 0)
				cout << k << "/" << 1;
			else
				cout << 1 << "/" << k;
			break;
		}
		else if (k*(k + 1) / 2 > n)
		{
			if (k % 2 == 0)
			{
				int cnt = n - k*(k - 1) / 2;
				cout << cnt << "/" << k - cnt + 1;
			}
			else
			{
				int cnt = n - k*(k - 1) / 2;
				cout << k - cnt + 1 << "/" << cnt;
			}
			break;
		}
		k++;
	}
	return 0;
}
