#include <iostream>
using namespace std;
int main(void)
{
	int arr[1001] = { 0, };
	int n, k, cnt = 0;
	cin >> n >> k;
	for (int i = 2; i <= n; i++)
	{
		if (arr[i] == 0)
		{
			for (int j = i; j <= n; j += i)
			{
				if (arr[j] == 0)
				{
					arr[j] = 1, cnt++;
					if (cnt == k)
					{
						cout << j;
						return 0;
					}
				}
			}
		}
	}
}
