#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
	int b, c, d, tmp, i;
	int burger[1000], side[1000], drink[1000];
	int sum = 0, ans = 0;
	cin >> b >> c >> d;
	for (i = 0; i < b; i++)
	{
		cin >> burger[i];
		sum += burger[i];
	}
	for (i = 0; i < c; i++)
	{
		cin >> side[i];
		sum += side[i];
	}
	for (i = 0; i < d; i++)
	{
		cin >> drink[i];
		sum += drink[i];
	}

	sort(burger, burger + b);
	sort(side, side + c);
	sort(drink, drink + d);

	for (i = 0; b - i >= 1 && c - i >= 1 && d - i >= 1; i++)
	{
		ans += (burger[b - 1 - i] + side[c - 1 - i] + drink[d - 1 - i])*0.9;
	}
	for (int j = 0; j < b - i; j++)
		ans += burger[j];
	for (int j = 0; j < c - i; j++)
		ans += side[j];
	for (int j = 0; j < d - i; j++)
		ans += drink[j];
	cout << sum << endl << ans;
}
