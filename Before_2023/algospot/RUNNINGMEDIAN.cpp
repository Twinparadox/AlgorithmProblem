// RUNNINGMEDIAN - Unsolved Because of Running Time
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> arr;
	vector<int>::iterator it;

	int n;
	int c, a, b;
	int ans[20], cnt = 0, tmp, sum = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		arr.clear();
		cin >> c >> a >> b;
		arr.push_back(1983);
		sum = tmp = 1983;
		for (int j = 1; j < c; j++)
		{
			cnt = 0;
			for (it = arr.begin(); it < arr.end(); it++)
			{
				if (*it > (tmp*a + b) % 20090711)
				{
					arr.insert(it, (tmp*a + b) % 20090711);
					cnt++;
					tmp = (tmp*a + b) % 20090711;
					break;
				}
			}
			if (cnt == 0)
			{
				arr.push_back((tmp*a + b) % 20090711);
				tmp = (tmp*a + b) % 20090711;
			}
			if (arr.size() % 2 == 0)
				sum += (arr.at(arr.size() / 2 - 1));
			else
				sum += (arr.at(arr.size() / 2));
		}
		ans[i] = sum;
	}
	for (int i = 0; i < n; i++)
		cout << ans[i];
	return 0;
}
