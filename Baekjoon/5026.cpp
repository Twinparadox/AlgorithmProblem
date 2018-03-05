#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int n;
	string s;
	cin >> n;
	while (n--)
	{
		cin >> s;
		if (s == "P=NP")
			cout << "skipped\n";
		else
		{
			int ans, sub;
			string a, b;
			int len = s.length();
			for (int i = 0; i < len; i++)
			{
				if (s[i] == '+')
				{
					sub = i + 1;
					break;
				}
			}
			a = s.substr(0, sub);
			b = s.substr(sub, len - sub);
			ans = stoi(a) + stoi(b);
			cout << ans << '\n';
		}
	}
}
