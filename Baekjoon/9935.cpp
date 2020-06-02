#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
	string str, bomb;
	vector<char> ans;

	cin >> str >> bomb;

	int idx = 0, len = str.length(), bLen = bomb.length();
	ans.resize(len);
	for (int i = 0; i < len; i++)
	{
		ans[idx++] = str[i];
		if (ans[idx - 1] == bomb[bLen - 1])
		{
			if (idx - bLen < 0)
				continue;

			bool flag = true;
			for (int j = 0; j < bLen; j++)
			{
				if (ans[idx - j - 1] != bomb[bLen - j - 1])
				{
					flag = false;
					break;
				}
			}

			if (flag)
				idx -= bLen;
		}
	}

	if (idx <= 0)
		cout << "FRULA";
	else
	{
		for (int i = 0; i < idx; i++)
			cout << ans[i];
	}
}