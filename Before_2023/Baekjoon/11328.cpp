#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	while (n--)
	{
		string source, dest;
		int slen, dlen;
		int sArr[26] = { 0, }, dArr[26] = { 0, };
		bool same = true;
		cin >> source >> dest;

		slen = source.length();
		dlen = dest.length();
		if (slen != dlen)
			cout << "Impossible\n";
		else
		{
			for (int i = 0; i < slen; i++)
			{
				sArr[(int)(source[i] - 'a')]++;
				dArr[(int)(dest[i] - 'a')]++;
			}
			for (int i = 0; i < 26; i++)
			{
				if (sArr[i] != dArr[i])
				{
					same = false;
					break;
				}
			}

			if (same)
				cout << "Possible\n";
			else
				cout << "Impossible\n";
		}
	}
}
