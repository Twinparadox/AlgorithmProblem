#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int cnt = 0, ambg = 0;
	string str, ans = "";
	vector<string> original;

	cin >> str;
	int len = str.length();

	string substr = "";
	for (int i = 0; i < len; i++)
	{
		if (str[i] == ':')
		{
			if (substr != "")
			{
				original.push_back(substr);
				cnt++;
				substr = "";
			}
			if (str[i + 1] == ':')
			{
				original.push_back("-");
				i += 1;
			}
		}
		else
			substr += str[i];
	}
	if (substr != "")
	{
		cnt++;
		original.push_back(substr);
	}

	cnt = 8 - cnt;
	int size = original.size();
	for (int i = 0; i < size; i++)
	{
		if (original[i] == "-")
		{
			for (int j = 0; j < cnt; j++)
				ans += "0000:";
		}
		else
		{
			int subLen = original[i].length();
			string s = "";
			for (int j = 0; j < 4 - subLen; j++)
				s += "0";
			s = s + original[i] + ":";

			ans += s;
		}
	}

	for (int i = 0; i < 39; i++)
		cout << ans[i];
}