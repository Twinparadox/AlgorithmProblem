#include <iostream>
using namespace std;
int power(int x, int y)
{
	if (y == 0)
		return 1;
	else
	{
		if (y % 2 == 0)
			return power(x*x, y / 2);
		else
			return x * power(x*x, y / 2);
	}
}
void hanoi(int n, int from, int by, int to)
{
	if (n == 1)
	{
		cout << from << ' ' << to << '\n';
	}
	else
	{
		hanoi(n - 1, from, to, by);
		cout << from << ' ' << to << '\n';
		hanoi(n - 1, by, from, to);
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, ans;
	cin >> N;
	ans = power(2, N) - 1;
	cout << ans << '\n';
	hanoi(N, 1, 2, 3);
}