#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int s, len;
	char arr[10] = { 'A','E','I','O','U','a','e','i','o','u' };
	cin >> s;
	cin.ignore();
	while (s--)
	{
		int c = 0, v = 0;

		string str;
		getline(cin, str);

		len = str.length();
		for (int i = 0; i < len; i++)
		{
			bool check = false;
			if (str[i] == ' ')
				continue;
			for (int j = 0; j < 10; j++)
			{
				if (str[i] == arr[j])
				{
					check = true;
					break;
				}
			}
			if (check)
				v++;
			else
				c++;
		}
		cout << c << ' ' << v << '\n';
	}
}