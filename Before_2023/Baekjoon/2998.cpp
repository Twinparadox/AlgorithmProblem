#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(void)
{
	string s;
	int len, tmp;
	cin >> s;
	len = s.length();
	if (len % 3 == 2)
		s = "0" + s;
	else if (len % 3 == 1)
		s = "00" + s;
	len = s.length();

	for (int i = 0; i < len; i += 3)
	{
		tmp = 0;
		for (int j = 0; j < 3; j++)
			tmp += pow(2, 2 - j)*(int)((char)s[i + j] - '0');
		cout << tmp;
	}
}
