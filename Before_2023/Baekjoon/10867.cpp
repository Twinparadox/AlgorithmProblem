#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	int n, sum = 0, size = 0;
	vector<int> list;
	cin >> n;
	for (int i = 0, k; i < n; i++)
	{
		cin >> k;
		list.push_back(k);
	}
	size = list.size();
	sort(list.begin(),list.end());
	cout << list[0] << ' ';
	for (int i = 1; i < size; i++)
		if (list[i]!=list[i-1])
			cout << list[i] << ' ';
}
