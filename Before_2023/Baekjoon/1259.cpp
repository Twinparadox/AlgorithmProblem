#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	while (1)
	{
		string s;
		int len, i;
		cin >> s;
		if (s == "0")
			break;
		else
		{
			len = s.length();
			for (i = 0; i < len; i++)
				if (s[i] != s[len - 1 - i])
					break;
			cout << (i == len ? "yes\n" : "no\n");
		}
	}
}
