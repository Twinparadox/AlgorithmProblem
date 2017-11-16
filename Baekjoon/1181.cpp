#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(void)
{
	string tmp;
	vector<pair<int, string> > v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		v.push_back(pair<int, string>(tmp.length(), tmp));
	}
	sort(v.begin(), v.end());
	cout << v[0].second << "\n";
	for (int i = 1; i < n; i++)
	{
		if (v[i].second == v[i - 1].second)
			continue;
		cout << v[i].second << "\n";
	}
}
