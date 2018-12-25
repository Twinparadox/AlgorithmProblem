#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string a, b;
	int alphaA[26] = { 0, }, alphaB[26] = { 0, }, alen, blen, ans = 0;
	cin >> a >> b;
	alen = a.length();
	blen = b.length();

	for (int i = 0; i < alen; i++)
		alphaA[a[i] - 'a']++;
	for (int i = 0; i < blen; i++)
		alphaB[b[i] - 'a']++;

	for (int i = 0; i < 26; i++)
	{
		int tmp = alphaA[i] - alphaB[i];
		ans += tmp < 0 ? -tmp : tmp;
	}
	cout << ans;
}