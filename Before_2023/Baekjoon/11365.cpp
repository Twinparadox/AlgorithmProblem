#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	while (1)
	{
		int len;
		string s;
		getline(cin, s);
		if (s == "END")
			break;
		len = s.length();
		for (int i = len - 1; i >= 0; i--)
			cout << s[i];
		cout << '\n';
	}
}
