#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
	string plain, key;
	int pLen, keyLen;

	getline(cin, plain);
	cin >> key;
	pLen = plain.length();
	keyLen = key.length();

	vector<char> crypt(pLen);

	for (int i = 0; i < pLen; i++)
	{
		if (plain[i] == ' ')
			crypt[i] = ' ';
		else
		{
			int keyValue = key[i%keyLen] - 'a' + 1;
			int charValue = plain[i] - 'a';
			if (charValue - keyValue >= 0)
				crypt[i] = charValue - keyValue + 'a';
			else
				crypt[i] = 26 + charValue - keyValue + 'a';
		}
	}

	for (int i = 0; i < pLen; i++)
		cout << crypt[i];
}