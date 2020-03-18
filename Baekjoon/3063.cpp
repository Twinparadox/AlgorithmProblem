#include <algorithm>
#include <iostream>
using namespace std;
int MIN(int a, int b)
{
	return a < b ? a : b;
}
int MAX(int a, int b)
{
	return a > b ? a : b;
}
int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		int x1, y1, x2, y2, x3, y3, x4, y4, ans = 0;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

		ans = (x2 - x1)*(y2 - y1);

		if (x2 <= x3 || x4 <= x1 || y2 <= y3 || y4 <= y1)
			cout << ans;
		else
		{
			ans -= (MIN(x2, x4) - MAX(x1, x3)) * (MIN(y2, y4) - MAX(y1, y3));
			cout << ans;
		}
		cout << '\n';
	}
}