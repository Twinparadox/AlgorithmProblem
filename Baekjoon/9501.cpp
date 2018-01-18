#include <iostream>
using namespace std;
int main(void)
{
	int t, cnt, n, d, v, c, f;
	cin >> t;
	while (t--)
	{
		cin >> n >> d;
		cnt = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> v >> f >> c;
			if (f*(double)v / c >= d)
				cnt++;
		}
		cout << cnt << '\n';
	}
}
