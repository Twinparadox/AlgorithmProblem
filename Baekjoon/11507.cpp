#include <iostream>
#include <string>
using namespace std;
void count(int arr[])
{
	int cnt = 0;
	for (int i = 1; i <= 13; i++)
		if (arr[i] == 0)
			cnt++;
	cout << cnt << ' ';
}
int main(void)
{
	string s;
	int p[14] = { 0, }, k[14] = { 0, }, h[14] = { 0, }, t[14] = { 0, }, len, cnt;
	cin >> s;
	len = s.length();
	for (int i = 0; i < len; i += 3)
	{
		int su = stoi(s.substr(i + 1, 2));
		if (s[i] == 'P')
		{
			p[su]++;
			if (p[su] > 1)
			{
				cout << "GRESKA";
				return 0;
			}
		}
		else if(s[i]=='K')
		{
			k[su]++;
			if (k[su] > 1)
			{
				cout << "GRESKA";
				return 0;
			}
		}
		else if (s[i] == 'H')
		{
			h[su]++;
			if (h[su] > 1)
			{
				cout << "GRESKA";
				return 0;
			}
		}
		else
		{
			t[su]++;
			if (t[su] > 1)
			{
				cout << "GRESKA";
				return 0;
			}
		}
	}
	count(p);
	count(k);
	count(h);
	count(t);
}
