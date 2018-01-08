#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(void)
{
	string s, subs;
	int n, p, len, sum = 0;
	cin >> s;
	len = s.length();
	if (s[0] == '0' && s[1] == 'x')
	{
		for (int i = 2; i < len; i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
				sum += (int)((char)s[i] - '0')*pow(16, len - 1 - i);
			else
				sum += (int)((char)s[i] - 'a' + 10)*pow(16, len - 1 - i);
		}
	}
	else if (s[0] == '0')
	{
		for (int i = 1; i < len; i++)
			sum += (int)((char)s[i] - '0')*pow(8, len - 1 - i);
	}
	else
	{
		for (int i = 0; i < len; i++)
			sum += (int)((char)s[i] - '0')*pow(10, len - 1 - i);
	}
	cout << sum;
}
