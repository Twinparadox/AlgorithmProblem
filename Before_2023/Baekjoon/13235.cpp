#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string s;
	int len, i;
	cin >> s;
	len = s.length();
	for (i = 0; i < len; i++)
		if (s[i] != s[len - 1 - i])
			break;
	cout << (i == len ? "true" : "false");
}
