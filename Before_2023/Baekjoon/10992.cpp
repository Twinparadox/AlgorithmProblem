#include <iostream>
using namespace std;
int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		if (i == 0)
		{
			for (int i = 0; i < N - 1; i++)
				cout << ' ';
			cout << '*';
		}
		else if (i == N - 1)
		{
			for (int j = 0; j < N * 2 - 1; j++)
				cout << '*';
		}
		else
		{
			for (int j = 0; j < N - 1 - i; j++)
				cout << ' ';
			cout << '*';
			for (int j = 0; j < (i - 1) * 2 + 1; j++)
				cout << ' ';
			cout << '*';
		}
		cout << '\n';
	}
}