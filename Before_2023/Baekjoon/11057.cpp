#include <iostream>
using namespace std;
int main(void)
{
	int d[1001][11] = { 0, }, n, ans = 0;
	cin >> n;
	for (int i = 1; i <= 10; i++)
	{
		d[1][i] = 1;
	}
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= 10; j++)
			for (int k = j; k <= 10; k++)
				d[i][j] = (d[i][j] + d[i - 1][k]) % 10007;
	for (int i = 1; i <= 10; i++)
		ans = (ans + d[n][i]) % 10007;
	cout << ans;
}
