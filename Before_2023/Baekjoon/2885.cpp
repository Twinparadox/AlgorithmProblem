#include <iostream>
using namespace std;
int main(void)
{
	int tmp = 1, n = 0, size = 0, k, min, cnt = 0;
	cin >> k;
	while (tmp < k)
	{
		tmp *= 2;
		n++;
	}
	while (k > 0)
	{
		cnt++;
		if (k % 2 == 1)
			break;
		k /= 2;
	}    
	cout << tmp << ' ' << n - cnt + 1;
}
