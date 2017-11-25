#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <algorithm>
using namespace std;
int main(void)
{
	int n;
	map<string, bool, greater<string> > list;
	cin >> n;
	while (n--)
	{
		string name, op;
		cin >> name >> op;
		if (op == "enter")
			list[name] = true;
		else
			list[name] = false;
	}
	for (map<string, bool, greater<string> >::iterator it = list.begin(); it != list.end(); it++)
		if (it->second == true)
			cout << it->first << '\n';
}
