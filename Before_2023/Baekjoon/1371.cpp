#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
	int arr[26] = { 0, }, size, len, max = 0;
	vector<string> s;
	string str;

	while (getline(cin, str))
		s.push_back(str);

	size = s.size();
	for (int i = 0; i < size; i++)
	{
		len = s[i].length();
		for (int j = 0; j < len; j++)
		{
			if ((char)s[i][j] != ' ')
				arr[(int((char)s[i][j] - 'a'))]++;
		}
	}
	for (int i = 0; i < 26; i++)
		max = max < arr[i] ? arr[i] : max;

	for (int i = 0; i < 26; i++)
		if (max == arr[i])
			cout << (char)(i + 'a');
}
