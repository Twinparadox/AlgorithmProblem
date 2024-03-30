#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int n, len;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		len = s.length();
		if (s[len / 2 - 1] == s[len / 2])
			cout << "Do-it\n";
		else
			cout << "Do-it-Not\n";
	}
}
