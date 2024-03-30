#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string str;
	int len;

	cin >> str;
	len = str.length();
	int cnt = 0, ans = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '(')
			cnt++;
		else
			cnt--;

		if (cnt < 0)
		{
			cnt += 2;
			ans++;
		}
	}

	ans += cnt / 2;
	cout << ans;
}