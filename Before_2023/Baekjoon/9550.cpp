#include <iostream>
using namespace std;
int main(void)
{
	int t, n, k, arr[100], cnt;
	cin >> t;
	while (t--)
	{
		cnt = 0;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			cnt += arr[i] / k;
		}
		cout << cnt << "\n";
	}
}
