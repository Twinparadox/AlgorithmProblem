#include <iostream>
using namespace std;
int main(void)
{
	int b, result;
	char op;
	cin >> result;
	while (1)
	{
		cin >> op;
		if (op == '=')
		{
			cout << result;
			break;
		}
		else
		{
			cin >> b;
			if (op == '+')
				result += b;
			else if (op == '-')
				result -= b;
			else if (op == '*')
				result *= b;
			else if (op == '/')
				result /= b;
		}
	}
}
