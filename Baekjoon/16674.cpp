#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string str;
	int su[10] = { 0, }, len, ans;
	bool check = false;

	cin >> str;
	len = str.length();
	for (int i = 0; i < len; i++)
		su[(int)str[i] - '0']++;

	for (int i = 0; i < 10; i++)
	{
		if (i == 0 || i == 1 || i == 2 || i == 8)
			continue;
		else
		{
			if (su[i] != 0)
			{
				check = true;
				break;
			}
		}
	}

	if (check)
	{
		ans = 0;
	}
	else if (su[0] != 0 || su[1] != 0 || su[2] != 0 || su[8] != 0)
	{
		ans = 1;
		if (su[0] != 0 && su[1] != 0 && su[2] != 0 && su[8] != 0)
		{
			ans = 2;
			if (su[0] == su[1] && su[1] == su[2] && su[2] == su[8])
			{
				ans = 8;
			}
		}
	}
	cout << ans;
}