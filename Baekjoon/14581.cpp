#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string s;
	cin >> s;
	for (int i = 0; i < 3; i++)
	{
		if (i != 1)
			for (int j = 0; j < 3; j++)
				cout << ":fan:";
		else
			cout << ":fan::" << s << "::fan:";
		cout << "\n";
	}
}
