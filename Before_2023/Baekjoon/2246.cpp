#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int n, cnt = 0;
	bool check;
	cin >> n;
	vector<pair<int, int> > arr(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;

	for (int i = 0; i < n; i++)
	{
		check = false;
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				if (arr[i].first > arr[j].first)
				{
					if (arr[i].second >= arr[j].second)
					{
						check = true;
						break;
					}
				}
				else if (arr[i].second > arr[j].second)
				{
					if (arr[i].first >= arr[j].first)
					{
						check = true;
						break;
					}
				}
			}
		}
		if (!check)
			cnt++;
	}

	cout << cnt;
}
