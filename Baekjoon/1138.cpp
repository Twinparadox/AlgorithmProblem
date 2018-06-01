#include <iostream>
using namespace std;
int main(void)
{
	int n;
	int arr[10], ans[11] = { 0, };
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	ans[arr[0] + 1] = 1;
	for (int i = 1; i < n; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			if (cnt == arr[i] && ans[j] == 0)
			{
				ans[j] = i + 1;
				break;
			}
			if (ans[j] > i + 1 || ans[j] == 0)
				cnt++;
		}
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
}
