#include <iostream>
using namespace std;
int main(void)
{
	int t, n, m;
	cin >> t;
	while (t--)
	{
		int cnt = 0;
		cin >> n >> m;
		for (int a = 1; a < n; a++)
		{
			for (int b = a + 1; b < n; b++)
			{
				double su = (double)(a*a + b * b + m) / (a*b);
				if (su - (int)su == 0)
					cnt++;
			}
		}
		cout << cnt << '\n';
	}
}