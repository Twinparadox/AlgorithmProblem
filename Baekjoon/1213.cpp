#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
	string str, pal = "";
	int len, cnt = 0, oddIdx;
	vector<int> alpha(26, 0);

	cin >> str;
	len = str.length();

	for (int i = 0; i < len; i++)
		alpha[str[i] - 'A']++;

	for (int i = 0; i < 26; i++)
		if (alpha[i] % 2 == 1)
			cnt++, oddIdx = i;

	if ((len % 2 == 0 && cnt > 0) || (len % 2 == 1 && cnt > 1))
	{
		cout << "I'm Sorry Hansoo";
	}
	else
	{
		for (int i = 0; i < 26; i++)
			for (int j = 0; j < alpha[i] / 2; j++)
				pal += (char)('A' + i);

		if (len % 2 == 1)
			pal += (char)('A' + oddIdx);

		for (int i = 25; i >= 0; i--)
			for (int j = 0; j < alpha[i] / 2; j++)
				pal += (char)('A' + i);

		cout << pal;
	}
}