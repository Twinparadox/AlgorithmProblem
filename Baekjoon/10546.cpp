#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(void)
{
	map<string, int> list;
	int n;
	string tmp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (list.find(tmp) != list.end())
			list[tmp]++;
		else
			list[tmp] = 1;
	}
	for (int i = 0; i < n - 1; i++)
	{
		cin >> tmp;
		if (list[tmp] == 1)
			list.erase(tmp);
		else
			list[tmp]--;
	}
	cout << list.begin()->first;
}
