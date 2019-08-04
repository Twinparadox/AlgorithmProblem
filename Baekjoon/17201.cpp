#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int N, pole;
	bool linked = true;
	string str;
	cin >> N;
	cin >> str;

	pole = str[0] - '0';
	for (int i = 1; i < N * 2; i++)
	{
		if (pole == str[i] - '0')
		{
			linked = false;
			break;
		}
		else
			pole = str[i] - '0';
	}

	if (!linked)
		cout << "No";
	else
		cout << "Yes";
}