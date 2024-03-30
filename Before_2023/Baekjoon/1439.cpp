#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string s;
	int len, zeropart = 0, onepart = 0, cnt = 0;
	cin >> s;
	len = s.length();

	if (s[0] == '0')
		zeropart = 1;
	else
		onepart = 1;
	for (int i = 1; i < len; i++)
	{
		if (s[i] != s[i - 1])
		{
			if (s[i] == '0')
				zeropart++;
			else
				onepart++;
		}
	}
	cout << ((onepart < zeropart) ? onepart : zeropart);
}
