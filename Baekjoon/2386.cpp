#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	char op;
	while (1)
	{
		cin >> op;
		if (op == '#')
			break;
		string s;
		int size, cnt = 0;
		getline(cin, s);
		size = s.length();
		for (int i = 0; i < size; i++)
			if (s[i] == op || ((s[i] >= 'A' && s[i] <= 'Z') && ((s[i] == (op - 'a' + 'A')))))
				cnt++;
		cout << op << ' ' << cnt << '\n';
	}
}
