#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int main(void)
{
	int n, x, y;
	vector<pair<int, int> > v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		v.push_back(pair<int, int>(x, y));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
		cout << v[i].first << " " << v[i].second << "\n";
}
