#include <iostream>
using namespace std;
int main(void)
{
	int N, R, C;
	int x, y;
	cin >> N >> R >> C;

	x = R % 2;
	y = C % 2;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (j % 2 == y)
			{
				if (i % 2 == x)
					cout << 'v';
				else
					cout << '.';
			}
			else
			{
				if (i % 2 == x)
					cout << '.';
				else
					cout << 'v';
			}
		}
		cout << '\n';
	}
}