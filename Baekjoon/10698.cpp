#include <iostream>
using namespace std;
int main(void)
{
	int t, x, y, z;
	char op1, op2;
	cin >> t;
	for(int i=1;i<=t;i++)
	{
		cin >> x >> op1 >> y >> op2 >> z;
		switch (op1)
		{
		case '+':
			if (x + y == z)
				cout << "Case " << i << ": YES";
			else
				cout << "Case " << i << ": NO";
			break;
		case '-':
			if (x - y == z)
				cout << "Case " << i << ": YES";
			else
				cout << "Case " << i << ": NO";
			break;
		default:
			break;
		}
		cout << '\n';
	}
}
