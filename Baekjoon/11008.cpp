#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		int cnt = 0, ans = 0, sLen, pLen;;
		string s, p;
		cin >> s >> p;

		sLen = s.length();
		pLen = p.length();
		if (pLen == 1)
		{
			ans = sLen;
		}
		else
		{
			string tmp = "";
			while (1)
			{
				int subLen = s.length();
				int idx = s.find(p);
				if (idx == string::npos)
				{
					tmp += s;
					break;
				}

				ans++;
				tmp += s.substr(0, idx);
				s = s.substr(idx + pLen, subLen - pLen);
			}
			ans += tmp.length();
		}
		cout << ans << '\n';
	}
}