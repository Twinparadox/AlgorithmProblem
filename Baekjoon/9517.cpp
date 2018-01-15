#include <iostream>
using namespace std;
int main(void)
{
	int k, n, time = 210, ans, t;
	char z;
	bool check = false;
	cin >> k >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t >> z;
		if (time - t <= 0 && !check)
		{
			ans = k;
			check = true;
		}
		else
		{
			time -= t;
			if (z == 'T')
				k = (k + 1) > 8 ? 1 : (k + 1);
		}
	}
	cout << ans;
}
