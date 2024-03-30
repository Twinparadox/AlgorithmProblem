#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		string a, b;
		int alen, blen, aa[26] = { 0, }, bb[26] = { 0, };
		bool anagram = true;
		cin >> a >> b;
		alen = a.length(), blen = b.length();
		for (int i = 0; i < alen; i++)
			aa[(int)((char)a[i] - 'a')]++;
		for (int i = 0; i < blen; i++)
			bb[(int)((char)b[i] - 'a')]++;
		for (int i = 0; i < 26; i++)
			if (aa[i] != bb[i])
				anagram = false;
		if (anagram)
			cout << a << " & " << b << " are anagrams.\n";
		else
			cout << a << " & " << b << " are NOT anagrams.\n";
	}
}
