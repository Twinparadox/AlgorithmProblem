#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int t, len;
	double res;
	cin >> t;
	cout.precision(2);
	while (t--)
	{
		cin >> res;
		string op;
		cin.ignore();
		getline(cin, op);
		len = op.length();
		for (int i = 0; i < len; i += 2)
		{
			if ((char)op[i] == '@')
				res *= 3;
			else if ((char)op[i] == '%')
				res += 5;
			else if ((char)op[i] == '#')
				res -= 7;
		}
		cout << fixed << res << '\n';
	}
}
