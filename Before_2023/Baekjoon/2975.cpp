#include <iostream>
using namespace std;
int main(void)
{
	int n, m, result;
	char op;
	while (1)
	{
		cin >> n >> op >> m;
		if (n == 0 && op == 'W' && m == 0)
			break;
		if (op == 'W')
		{
			if (n - m < -200)
				cout << "Not allowed";
			else
				cout << n - m;
		}
		else
		{
			cout << n + m;
		}
		cout << '\n';
	}
}