#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string operator+(string &a, string &b)
{
	string c;
	int s1 = a.size(), s2 = b.size(), dec = 0;
	for (int i = s1 - 1, j = s2 - 1; (i >= 0 || j >= 0); i--, j--)
	{
		int d;
		if (i >= 0 && j >= 0)
			d = (a[i] - '0') + (b[j] - '0') + dec;
		else if (i >= 0 && j<0)
			d = (a[i] - '0') + dec;
		else if (i<0 && j >= 0)
			d = (b[j] - '0') + dec;
		
		if (d < 10)
		{
			c += d + '0';
			dec = 0;
		}
		else
		{
			dec = d / 10;
			c += d % 10 + '0';
		}
	}
	if (dec)
		c += dec + '0';
	reverse(c.begin(), c.end());
	return c;
}
int main()
{
	int n;
	cin >> n;
	string f1 = "1", f2 = "1", f3;
	for (int i = 3; i <= n; i++)
	{
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}
	if (n == 1 || n == 2)
		cout << 1;
	else
		cout << f3;
}

