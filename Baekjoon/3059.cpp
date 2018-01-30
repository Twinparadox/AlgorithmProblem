#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int t, sum, len;
	cin >> t;
	while (t--)
	{
		string s;
		bool check[26] = { false, };
		cin >> s;
		
		sum = 0, len = s.length();
		for (int i = 0; i < len; i++)
			check[(char)s[i] - 'A'] = true;
		for (int i = 0; i < 26; i++)
			if (!check[i])
				sum += (i + 65);
		cout << sum << '\n';
	}
}
