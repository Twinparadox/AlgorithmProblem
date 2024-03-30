#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int len, vSize = 6, cSize = 20, vRot = 3, cRot = 10;
	string str;
	string vowel = "aiyeou";
	string VOWEL = "AIYEOU";
	string consonant = "bkxznhdcwgpvjqtsrlmf";
	string CONSONANT = "BKXZNHDCWGPVJQTSRLMF";

	while (getline(cin, str))
	{
		int len = str.length();
		for (int i = 0; i < len; i++)
		{
			int idx;
			for (int j = 0; j < vSize; j++)
				idx = vowel.find(str[i]);
			if (idx != string::npos)
			{
				cout << vowel[(idx + vRot) % vSize];
				continue;
			}

			for (int j = 0; j < vSize; j++)
				idx = VOWEL.find(str[i]);
			if (idx != string::npos)
			{
				cout << VOWEL[(idx + vRot) % vSize];
				continue;
			}

			for (int j = 0; j < cSize; j++)
				idx = consonant.find(str[i]);
			if (idx != string::npos)
			{
				cout << consonant[(idx + cRot) % cSize];
				continue;
			}

			for (int j = 0; j < cSize; j++)
				idx = CONSONANT.find(str[i]);
			if (idx != string::npos)
			{
				cout << CONSONANT[(idx + cRot) % cSize];
				continue;
			}

			cout << str[i];
		}
		cout << '\n';
	}
}