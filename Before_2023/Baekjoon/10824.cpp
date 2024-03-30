#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int a, b, c, d, abLen, cdLen, idx1, idx2, mod, check = 0;
	string ab, cd, ans = "";

	cin >> a >> b >> c >> d;

	ab = to_string(a) + to_string(b);
	cd = to_string(c) + to_string(d);
	abLen = ab.length();
	cdLen = cd.length();

	for (idx1 = abLen - 1, idx2 = cdLen - 1; idx1 >= 0 && idx2 >= 0; idx1--, idx2--)
	{
		if ((ab[idx1] - '0') + (cd[idx2] - '0') + check >= 10)
		{
			mod = (ab[idx1] - '0') + (cd[idx2] - '0') + check - 10;
			ans = to_string(mod) + ans;
			check = 1;
		}
		else
		{
			mod = (ab[idx1] - '0') + (cd[idx2] - '0') + check;
			ans = to_string(mod) + ans;
			check = 0;
		}
	}

	if (idx1 >= 0)
	{
		for (; idx1 >= 0; idx1--)
		{
			if (check + ab[idx1] - '0' >= 10)
			{
				mod = check + ab[idx1] - '0' - 10;
				ans = to_string(mod) + ans;
				check = 1;
			}
			else
			{
				mod = check + ab[idx1] - '0';
				ans = to_string(mod) + ans;
				check = 0;
			}
		}
	}
	else if (idx2 >= 0)
	{
		for (; idx2 >= 0; idx2--)
		{
			if (check + cd[idx2] - '0' >= 10)
			{
				mod = check + cd[idx2] - '0' - 10;
				ans = to_string(mod) + ans;
				check = 1;
			}
			else
			{
				mod = check + cd[idx2] - '0';
				ans = to_string(mod) + ans;
				check = 0;
			}
		}
	}
	if (check != 0)
	{
		ans = to_string(check) + ans;
	}
	cout << ans;
}