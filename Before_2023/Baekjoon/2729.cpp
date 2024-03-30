#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		string ans = "", a, b;
		int aLen, bLen;
		cin >> a >> b;

		aLen = a.length(), bLen = b.length();
		int re = 0, aIdx = aLen - 1, bIdx = bLen - 1;

		for (; aIdx >= 0 && bIdx >= 0; aIdx--, bIdx--)
		{
			int na = a[aIdx] - '0', nb = b[bIdx] - '0';
			if ((na + nb + re) >= 2)
			{
				ans = to_string((na + nb + re) % 2) + ans;
				re = 1;
			}
			else
			{
				ans = to_string(na + nb + re) + ans;
				re = 0;
			}
		}

		for (; aIdx >= 0; aIdx--)
		{
			int na = a[aIdx] - '0';
			if ((na + re) >= 2)
			{
				ans = to_string((na + re) % 2) + ans;
				re = 1;
			}
			else
			{
				ans = to_string(na + re) + ans;
				re = 0;
			}
		}
		for (; bIdx >= 0; bIdx--)
		{

			int nb = b[bIdx] - '0';
			if ((nb + re) >= 2)
			{
				ans = to_string((nb + re) % 2) + ans;
				re = 1;
			}
			else
			{
				ans = to_string(nb + re) + ans;
				re = 0;
			}
		}

		if (re)
			ans = "1" + ans;

		int len = ans.length(), first = 0;
		for (int i = 0; i < len - 1; i++)
		{
			if (!first && ans[i] == '1')
			{
				first = 1;
				cout << ans[i];
			}
			else if (!first && ans[i] == '0')
				continue;
			else
				cout << ans[i];
		}
		cout << ans[len - 1];
		cout << '\n';
	}
}