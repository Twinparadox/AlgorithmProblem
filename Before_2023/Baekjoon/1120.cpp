#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string a, b;
	int alen, blen, cnt, sub, min;
	cin >> a >> b;
	alen = a.length(), blen = b.length();

	min = alen, sub = blen - alen;
	for (int i = 0; i <= sub; i++)
	{
		cnt = 0;
		for (int j = 0; j < alen; j++)
		{
			if (a[j] != b[j + i])
				cnt++;
		}
		min = min < cnt ? min : cnt;
	}
	cout << min;
}
