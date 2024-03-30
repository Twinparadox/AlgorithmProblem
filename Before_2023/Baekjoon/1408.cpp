#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string str1, str2, ans = "";
	int len, sec1, sec2, sub, hr, min;
	cin >> str1 >> str2;
	sec1 = stoi(str1.substr(0, 2)) * 3600 + stoi(str1.substr(3, 2)) * 60 + stoi(str1.substr(6, 2));
	sec2 = stoi(str2.substr(0, 2)) * 3600 + stoi(str2.substr(3, 2)) * 60 + stoi(str2.substr(6, 2));

	if (sec1 > sec2)
		sub = 3600 * 24 - sec1 + sec2;
	else
		sub = sec2 - sec1;

	hr = sub / 3600;
	sub %= 3600;
	min = sub / 60;
	sub %= 60;

	if (hr < 10)
		ans += "0" + to_string(hr);
	else
		ans += to_string(hr);
	ans += ":";

	if (min < 10)
		ans += "0" + to_string(min);
	else
		ans += to_string(min);
	ans += ":";

	if (sub < 10)
		ans += "0" + to_string(sub);
	else
		ans += to_string(sub);

	cout << ans;
}