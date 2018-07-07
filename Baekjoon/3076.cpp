#include <iostream>
using namespace std;
int main(void)
{
	int r, c, a, b;
	cin >> r >> c >> a >> b;
	for (int i = 0; i < r; i++)
	{
		for (int k = 0; k < a; k++)
		{
			for (int j = 0; j < c; j++)
			{
				if ((i + j) % 2 == 0)
					for (int si = 0; si < b; si++)
						cout << "X";
				else
					for (int si = 0; si < b; si++)
						cout << ".";
			}
			cout << '\n';
		}
	}
}
