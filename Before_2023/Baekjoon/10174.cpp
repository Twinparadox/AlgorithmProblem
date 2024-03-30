#include <iostream>
#include <string>
using namespace std;
bool isAlphabet(char c)
{
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}
bool isCapital(char c)
{
	return (c >= 'A' && c <= 'Z');
}
int main(void)
{
	int N;
	cin >> N;
	cin.ignore();
	while (N--)
	{
		string str;
		int len;
		getline(cin, str);
		len = str.length();

		bool isNot = false;
		for (int i = 0; i < len / 2; i++)
		{
			if (isAlphabet(str[i]))
			{
				int front, rear;
				if (isCapital(str[i]))
					front = str[i] - 'A';
				else
					front = str[i] - 'a';

				if (isCapital(str[len - 1 - i]))
					rear = str[len - 1 - i] - 'A';
				else
					rear = str[len - 1 - i] - 'a';
				if (front != rear)
				{
					isNot = true;
					break;
				}
			}
			else
			{
				if (str[i] != str[len - 1 - i])
				{
					isNot = true;
					break;
				}
			}
		}

		if (isNot)
			cout << "No\n";
		else
			cout << "Yes\n";
	}
}