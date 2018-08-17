#include <iostream>
using namespace std;
int main(void)
{
	int n, arr[4], max = 0;
	cin >> n;
	while (n--)
	{
		int dice[7] = { 0, }, tmp=0;
		for (int i = 0; i < 4; i++)
		{
			cin >> arr[i];
			dice[arr[i]]++;
		}

		for (int i = 1; i <= 6; i++)
		{
			if (dice[i] == 4)
			{
				tmp = 50000 + i * 5000;
				break;
			}
		}

		if (tmp == 0)
		{
			for (int i = 1; i <= 6; i++)
			{
				if (dice[i] == 3)
				{
					tmp = 10000 + i * 1000;
					break;
				}
			}
		}

		if (tmp == 0)
		{
			int cnt = 0;
			for (int i = 1; i <= 6; i++)
			{
				if (dice[i] == 2)
				{
					cnt++;
					tmp += i;
				}
			}

			if (cnt == 2)
				tmp = 2000 + tmp * 500;
			else if (cnt == 1)
				tmp = 1000 + tmp * 100;
		}

		if (tmp == 0)
		{
			for (int i = 6; i >= 1; i--)
			{
				if (dice[i])
				{
					tmp = i * 100;
					break;
				}
			}
		}

		if (max < tmp)
			max = tmp;
	}
	cout << max;
}
