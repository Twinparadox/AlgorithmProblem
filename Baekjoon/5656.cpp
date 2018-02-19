#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int a, b;
	string op, res;
	for(int i=1;;i++)
	{
		cin >> a >> op >> b;
		if (op == "E")
			break;
		cout << "Case " << i << ": ";
		if (op == ">")
			res = (a > b) ? "true" : "false";
		else if (op == ">=")
			res = (a >= b) ? "true" : "false";
		else if (op == "<")
			res = (a < b) ? "true" : "false";
		else if (op == "<=")
			res = (a <= b) ? "true" : "false";
		else if (op == "==")
			res = (a == b) ? "true" : "false";
		else
			res = (a != b) ? "true" : "false";
		cout << res << '\n';
	}
}
