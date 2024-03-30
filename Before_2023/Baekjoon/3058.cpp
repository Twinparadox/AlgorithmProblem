#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	while (n--)
	{
		int sum = 0;
		vector<int> list;
		for (int n, i = 0; i < 7; i++)
		{
			cin >> n;
			if (n % 2 == 0)
				list.push_back(n), sum += n;
		}
		sort(list.begin(), list.end());
		cout << sum << ' ' << list[0] << '\n';
	}
}
