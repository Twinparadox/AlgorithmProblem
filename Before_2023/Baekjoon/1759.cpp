#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<char> arr;
int L, C;
bool isVowel(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	else
		return false;
}
void makePassword(int idx, string word, int cons, int vowel)
{
	if (cons + vowel == L)
	{
		if (cons >= 2 && vowel >= 1)
		{
			cout << word << '\n';
		}
		return;
	}

	for (int i = idx; i < C; i++)
	{
		string tmp = word + arr[i];
		if (isVowel(arr[i]))
			makePassword(i + 1, tmp, cons, vowel + 1);
		else
			makePassword(i + 1, tmp, cons + 1, vowel);
	}
}
int main(void)
{
	cin >> L >> C;
	arr = vector<char>(C);
	for (int i = 0; i < C; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());
	makePassword(0, "", 0, 0);
}
