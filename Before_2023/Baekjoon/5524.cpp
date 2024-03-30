#include <iostream>
#include <string>
#include <locale>
using namespace std;
int main(void)
{
	locale loc;
	int n;
	string *list;
	cin >> n;
	list = new string[n];
	for (int i = 0; i < n; i++)
		cin >> list[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < list[i].length(); j++)
			cout << tolower(list[i][j], loc);
		cout << '\n';
	}
}
