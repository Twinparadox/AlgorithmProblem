#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int n, len;
	cin >> n;
	cin.ignore();
	while (n--)
	{
		string s;
		bool alpha[26] = { false, }, check = true;
		getline(cin, s);
		len = s.length();
		for (int i = 0; i < len; i++)
		{
			if (s[i] >= 'a' && s[i] <= 'z')
				alpha[(int)(s[i] - 'a')] = true;
			else if (s[i] >= 'A' && s[i] <= 'Z')
				alpha[(int)(s[i] - 'A')] = true;
		}
		for (int i = 0; i < 26; i++)
			if (!alpha[i])
				check = false;
		if (check)
			cout << "pangram\n";
		else
		{
			cout << "missing ";
			for (int i = 0; i < 26; i++)
				if (!alpha[i])
					cout << (char)('a' + i);
			cout << '\n';
		}
	}
}
