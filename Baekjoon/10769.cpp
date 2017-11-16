#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string s;
	int len, happy = 0, sad = 0;
	getline(cin, s);
	len = s.size();
	for (int i = 0; i < len; i++)
	{
		if (s[i] == ':')
		{
			if (s[i + 1] == '-' && s[i + 2] == ')')
				happy++, i += 2;
			else if (s[i + 1] == '-' && s[i + 2] == '(')
				sad++, i += 2;
		}
	}
	if (happy == 0 && sad == 0)
		cout << "none";
	else if (happy == sad)
		cout << "unsure";
	else if (happy > sad)
		cout << "happy";
	else if (happy < sad)
		cout << "sad";
}
