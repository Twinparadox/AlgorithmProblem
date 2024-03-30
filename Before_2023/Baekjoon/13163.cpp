#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int n, sIdx, len;
	cin >> n;
	cin.ignore();
	while (n--)
	{
		string str;
		getline(cin, str);
		len = str.length();
		for (int i = 0; i < len; i++)
		{
			if (str[i] == ' ')
			{
				sIdx = i;
				break;
			}
		}
		cout << "god";
		for (int i = sIdx + 1; i < len; i++)
		{
			if (str[i] == ' ')
				continue;
			cout << str[i];
		}
		cout << '\n';
	}
}