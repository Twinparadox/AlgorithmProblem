#include <iostream>
using namespace std;
int main(void)
{
	int t, n, cnt;
	bool arr[101];
	cin >> t;
	while (t--)
	{
		cnt = 0;
		cin >> n;
		for (int i = 0; i <= n; i++)
			arr[i] = false;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; i*j <= n; j++)
			{
				if (arr[i*j])
					arr[i*j] = !arr[i*j];
				else
					arr[i*j] = !arr[i*j];
			}
		}
		for (int i = 1; i <= n; i++)
			if (arr[i] == true)
				cnt++;
		cout << cnt << "\n";
	}
}
