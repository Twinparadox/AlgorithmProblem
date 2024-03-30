#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	while (1)
	{
		string s;
		getline(cin, s);
		if (s == "#")
			break;
		bool check[26] = { false, };
		int size = s.length(), cnt = 0;
		for (int i = 0; i < size; i++)
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
				check[s[i] - 'A'] = true;
			else if (s[i] >= 'a'&& s[i] <= 'z')
				check[s[i] - 'a'] = true;
		}
		for (int i = 0; i < 26; i++)
			if (check[i])
				cnt++;
		cout << cnt << '\n';
	}
}
