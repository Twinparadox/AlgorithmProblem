#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int len;
	string str;
	cin >> str;
	len = str.length();
	for (int i = 0; i < len; i++)
	{
		cout << (char)(str[i] - 'a' + 'A');
	}
}