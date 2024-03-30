#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string poly;
	int x;
	cin >> poly;
	x = poly.find('x');
	if (x == string::npos)
	{
		cout << "0";
	}
	else
	{
		if (x == 0)
		{
			cout << "1";
		}
		else
		{
			if (x == 1 && poly[0] == '-')
			{
				cout << "-1";
			}
			else
			{
				cout << poly.substr(0, x);
			}
		}
	}
}