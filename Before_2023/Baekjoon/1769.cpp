#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string s;
	int n = 0, cnt, tmp1, tmp2, len;
	cin >> s;
	len = s.length();
	if (len > 1)
	{
		cnt = 1;
		for (int i = 0; i < len; i++)
			n += (int)(s[i] - '0');
	}
	else
	{
		cnt = 0;
		n = (int)(s[0] - '0');
	}
	while (n >= 10)
	{
		cnt++;
		tmp1 = n;
		tmp2 = 0;
		while (tmp1>0)
		{
			tmp2 += tmp1 % 10;
			tmp1 /= 10;
		}
		n = tmp2;
	}
	if (n % 3 == 0)
		cout << cnt << "\nYES";
	else
		cout << cnt << "\nNO";
}
