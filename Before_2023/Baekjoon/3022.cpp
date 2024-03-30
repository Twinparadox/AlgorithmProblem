#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(void)
{
	int n, ans = 0;
	map<string, int> owner;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;

		int sum = 0;
		for (auto i : owner)
		{
			if (i.first == tmp)
				continue;
			else
				sum += i.second;
		}

		if (sum < owner[tmp])
			ans++;
		owner[tmp]++;
	}
	cout << ans;
}