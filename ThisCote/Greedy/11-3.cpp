#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int len, zero = 0, one = 0;
	string str;
	cin >> str;

	len = str.length();
	if (str[0] == '0')
		zero++;
	else
		one++;
	for (int i = 1; i < len; i++)
	{
		if (str[i] != str[i - 1])
		{
			if (str[i] == '0')
				zero++;
			else
				one++;
		}
	}

	int ans = one < zero ? one : zero;
	cout << ans;
}