#include <iostream>
using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	long long sum = 0, ans = 0;
	cin >> n;
	ans = n * (n - 1) / 2;
	for (int i = 0, tmp; i < n; i++)
	{
		cin >> tmp;
		sum += tmp;
	}
	cout << sum - ans;
}
