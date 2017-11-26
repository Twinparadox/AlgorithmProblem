#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int t, sum, len;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		string s;
		getline(cin, s);
		len = s.length() , sum = 0;
		for (int i = 0; i < len; i += 2)
			sum += (int)s[i] - '0';
		cout << sum << '\n';
	}
}
