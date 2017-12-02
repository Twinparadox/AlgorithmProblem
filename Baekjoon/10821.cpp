#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string s;
	int cnt = 0, len;
	cin >> s;
	len = s.length();
	for (int i = 0; i < len; i++)
		if (s[i] == ',')
			cnt++;
	if (s[len - 1] == ',')
		cnt--;
	cout << cnt + 1;
}
