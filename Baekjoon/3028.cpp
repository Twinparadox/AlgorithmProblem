#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string s;
	int len, ball = 1;
	cin >> s;
	len = s.length();
	for (int i = 0; i < len; i++)
	{
		if (s[i] == 'A')
		{
			if (ball == 1)
				ball = 2;
			else if (ball == 2)
				ball = 1;
		}
		else if (s[i] == 'B')
		{
			if (ball == 2)
				ball = 3;
			else if (ball == 3)
				ball = 2;
		}
		else
		{
			if (ball == 1)
				ball = 3;
			else if (ball == 3)
				ball = 1;
		}
	}
	cout << ball;
}
