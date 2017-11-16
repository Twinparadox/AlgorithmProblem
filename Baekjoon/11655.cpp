#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string s;
	int len;
	getline(cin, s);
	len = s.size();
	for (int i = 0; i < len; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			cout << s[i];
		else if (s[i] >= 'A' && s[i] <= 'Z')
			cout << (char)((s[i] - 'A' + 13) % 26 + 'A');
		else if (s[i] >= 'a' && s[i] <= 'z')
			cout << (char)((s[i] - 'a' + 13) % 26 + 'a');
		else
			cout << s[i];
	}
}
