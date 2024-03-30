#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string a, b;
	int alen, blen, s1, s2;
	cin >> a >> b;
	alen = a.length(), blen = b.length();
	for (int i = 0; i < alen; i++)
		if (a[i] == '5')
			a[i] = '6';
	for (int i = 0; i < blen; i++)
		if (b[i] == '5')
			b[i] = '6';
	s1 = stoi(a) + stoi(b);
	for (int i = 0; i < alen; i++)
		if (a[i] == '6')
			a[i] = '5';
	for (int i = 0; i < blen; i++)
		if (b[i] == '6')
			b[i] = '5';
	s2 = stoi(a) + stoi(b);
	cout << s2 << ' ' << s1;
}
