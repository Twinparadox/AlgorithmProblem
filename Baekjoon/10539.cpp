#include <iostream>
using namespace std;
int main(void)
{
	int n, arr[101];
	long long sum[101] = { 0, };
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 1; i <= n; i++)
	{
		sum[i] = (long long) arr[i] * (long long )i;
		cout << sum[i] - sum[i - 1] << ' ';
	}
}
