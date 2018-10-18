#include <iostream>
#include <string>
using namespace std;
int gcd(int a,int  b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}
int main(void)
{
	string str;
	int pos, g, a, b, len;
	cin >> str;
	len = str.length();
	pos = str.find(':');
	a = stoi(str.substr(0, pos));
	b = stoi(str.substr(pos + 1, len - pos));

	if (a > b)
		g = gcd(a, b);
	else
		g = gcd(b, a);

	cout << a / g << ":" << b / g;
}
