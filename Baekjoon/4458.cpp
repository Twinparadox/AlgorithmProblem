#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	cin.ignore();
	while (n--)
	{
		string s;
		getline(cin, s);
		if (s[0] >= 'a' && s[0] <= 'z')
			s[0] = (char)(s[0] - 'a' + 'A');
		cout << s << '\n';
	}
}
