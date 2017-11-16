#include <iostream>
using namespace std;
int main(void)
{
	int t, m, k1;
	char op, k2;
	cin >> t;
	while (t--)
	{
		cin >> m >> op;
		if (op == 'C')
		{
			for (int i = 0; i < m; i++)
			{
				cin >> k2;
				cout << (int)(k2 - 64) << " ";
			}
		}
		else
		{
			for (int i = 0; i < m; i++)
			{
				cin >> k1;
				cout << (char)(k1 + 64) << " ";
			}
		}
		cout << "\n";
	}
}
