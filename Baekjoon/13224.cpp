#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string str;
	int len, idx = 1;
	cin >> str;
	len = str.length();

	for (int i = 0; i < len; i++)
	{
		switch (str[i])
		{
		case 'A':
			if (idx == 1)
				idx = 2;
			else if (idx == 2)
				idx = 1;
			break;
		case 'B':
			if (idx == 2)
				idx = 3;
			else if (idx == 3)
				idx = 2;
			break;
		case 'C':
			if (idx == 1)
				idx = 3;
			else if (idx == 3)
				idx = 1;
			break;
		default:
			break;
		}
	}

	cout << idx;
}