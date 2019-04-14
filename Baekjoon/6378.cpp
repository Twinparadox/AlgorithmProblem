#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string s;
	while (1)
	{
		cin >> s;
		if (s == "0")
			break;
		int sum = 0, len;
		len = s.length();
		while (len > 1)
		{
			string ans = "";
			for (int i = 0; i < len; i++)
				sum += (int)(s[i] - '0');
			ans = to_string(sum);
			len = ans.length();
			s = ans;
			sum = 0;
		}
		cout << s << '\n';
	}
}