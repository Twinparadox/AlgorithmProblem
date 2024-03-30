#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int t, len;
	bool real = true;
	cin >> t;
	while (t--)
	{
		string s;
		int arr[26] = { 0, };
		cin >> s;
		len = s.length(), real = true;
		for (int i = 0; i < len; i++)
		{
			arr[(char)s[i] - 'A']++;
			if (arr[(char)s[i] - 'A'] > 0 && arr[(char)s[i] - 'A'] % 3 == 0)
			{
				if (s[i + 1] != s[i] || i == len - 1)
				{
					real = false;
					break;
				}
				i++;
			}
		}
		if (real)
			cout << "OK\n";
		else
			cout << "FAKE\n";
	}
}
