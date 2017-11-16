#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	int t, n, l;
	string tmp;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<pair<int, string> > list;
		for (int i = 0; i < n; i++)
		{
			cin >> tmp >> l;
			list.push_back(make_pair(l, tmp));
		}
		sort(list.begin(), list.end());
		cout << list[list.size()-1].second << "\n";
	}
}
