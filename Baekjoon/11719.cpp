#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string s;
	for (int i = 0; i < 100; i++)
	{
		getline(cin, s);
		if (cin.eof())
			break;
		cout << s << '\n';
	}
}
