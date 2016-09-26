#include <iostream>
#include <cstring>
using namespace std;

typedef struct {
	int volume;
	int needs;
	double npv;
	char tname[20];
}things;

int main()
{
	int n;
	int max;
	int now = 0;
	int cnt = 0, knt = 0;
	int arr[100];
	things* t;
	things tmp;

	cin >> n >> max;
	t = new things[n];

	for (int i = 0; i < n; i++)
	{
		cin >> t[i].tname;
		cin >> t[i].volume >> t[i].needs;
		t[i].npv = (double)t[i].needs / t[i].volume;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (t[j].npv < t[j + 1].npv)
			{
				tmp = t[j];
				t[j] = t[j + 1];
				t[j + 1] = tmp;
			}
			else if (t[j].npv == t[j + 1].npv)
			{
				if (t[j].volume < t[j + 1].volume)
				{
					tmp = t[j];
					t[j] = t[j + 1];
					t[j + 1] = tmp;
				}
			}
		}
	}
	while (now <= max)
	{
		if (now + t[cnt].volume > max)
		{
			cnt++;
			continue;
		}

		now += t[cnt++].volume;
		arr[knt++] = cnt;
	}
	cout << cnt;
}
