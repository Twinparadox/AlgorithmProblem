#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
	string num;
	vector<string> arr;
	int k;
	cin >> num;
	cin >> k;
	while (k--)
	{
		string s;
		cin >> s;
		bool check = true;
		for (int i = 0; i < 9; i++)
		{
			if (num[i] == '*')
			{
				continue;
			}
			else if (num[i] != s[i])
			{
				check = false;
				break;
			}
		}

		if (check)
			arr.push_back(s);
	}

	cout << arr.size() << '\n';
	for (vector<string>::iterator iter = arr.begin(); iter != arr.end(); iter++)
		cout << *iter << '\n';
}