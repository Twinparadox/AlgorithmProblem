#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int len, cnt;
	while (1)
	{
		string s;
		getline(cin, s);
		if (s == "#")
			break;
		len = s.length(), cnt = 0;
		for (int i = 0; i < len; i++)
			if (s[i] == 'A' || s[i] == 'a' || s[i] == 'E' || s[i] == 'e' || s[i] == 'I' || s[i] == 'i' || s[i] == 'O' || s[i] == 'o' || s[i] == 'U' || s[i] == 'u')
				cnt++;
		cout << cnt << '\n';
	}
}
