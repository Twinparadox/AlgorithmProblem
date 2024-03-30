#include <iostream>
#include <vector>
using namespace std;
int main(void)
{

	int n, b, a, full;
	cin >> n >> b >> a;
	vector<int> v(n);
	full = a;
	for (int i = 0; i < n; i++)
		cin >> v[i];

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (a == 0 && b == 0)
			break;
		if (a == 0)
		{
			b--;
			if (v[i] == 1 && a < full)
				a++;
		}
		else if (b == 0)
		{
			a--;
		}
		else
		{
			if (v[i] == 1)
			{
				if (a == full)
					a--;
				else
				{
					b--;
					if (a < full)
						a++;
				}
			}
			else
				a--;
		}
		ans++;
	}
	cout << ans;
}