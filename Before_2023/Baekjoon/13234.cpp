#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	bool a, b, ans;
	string aStr, bStr, op;
	cin >> aStr >> op >> bStr;

	if (aStr == "true")
		a = true;
	else
		a = false;
	if (bStr == "true")
		b = true;
	else
		b = false;

	if (op == "AND")
	{
		ans = a && b;
	}
	else
	{
		ans = a || b;
	}

	if (ans)
		cout << "true";
	else
		cout << "false";
}