#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	while (1)
	{
		int carry = 0;
		string s1, s2;
		cin >> s1 >> s2;

		if (s1 == "0" && s2 == "0")
			break;

		int len1 = s1.length(), len2 = s2.length();
		int c = 0, i, j;
		for (i = len1 - 1, j = len2 - 1; i >= 0 && j >= 0; i--, j--)
		{
			int su1, su2;
			su1 = s1[i] - '0';
			su2 = s2[j] - '0';

			if (su1 + su2 + c >= 10)
				c = 1, carry++;
			else
				c = 0;
		}

		if (i >= 0)
		{
			for (; i >= 0; i--)
			{
				int su = s1[i] - '0';
				if (su + c >= 10)
					c = 1, carry++;
				else
					c = 0;
			}
		}
		if (j >= 0)
		{
			for (; j >= 0; j--)
			{
				int su = s2[j] - '0';
				if (su + c >= 10)
					c = 1, carry++;
				else
					c = 0;
			}
		}
		cout << carry << '\n';
	}
}