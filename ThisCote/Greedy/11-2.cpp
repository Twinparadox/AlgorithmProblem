#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int len, ans = 0;
	string str;
	cin >> str;

	len = str.length();
	ans = str[0] - '0';
	for (int i = 1; i < len; i++)
	{
		int p = str[i] - '0';
		if (ans + p < ans*p)
			ans *= p;
		else
			ans += p;
	}
	cout << ans;
}