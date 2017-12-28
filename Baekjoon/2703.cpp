#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int t, len;
	cin >> t;
	while (t--)
	{
		cin.ignore();
		string ci, k;
		getline(cin, ci);
		cin >> k;
		len = ci.length();
		for (int i = 0; i < len; i++)
		{
			if ((char)ci[i] == ' ')
				cout << ' ';
			else
				cout << (char)(k[(int)(ci[i] - 'A')]);
		}
		cout << '\n';
	}
}
