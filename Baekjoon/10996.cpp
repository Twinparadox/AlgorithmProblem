#include <iostream>
using namespace std;
int main(void)
{
	int N;
	cin >> N;
	if (N == 1)
		cout << "*";
	else
	{
		for (int i = 0; i < N * 2; i++)
		{
			if (i % 2 == 0)
			{
				for (int j = 0; j < N; j++)
				{
					if (j % 2 == 0)
						cout << '*';
					else
						cout << ' ';
				}
			}
			else
			{
				for (int j = 0; j < N; j++)
				{
					if (j % 2 == 0)
						cout << ' ';
					else
						cout << '*';
				}
			}
			cout << '\n';
		}
	}
}