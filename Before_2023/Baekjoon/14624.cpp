#include <iostream>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	if (n % 2 == 0)
		cout << "I LOVE CBNU";
	else
	{
		for (int i = 0; i < n; i++)
			cout << '*';
		cout << '\n';
		for (int i = 0; i <= n / 2; i++)
		{
			for (int j = 0; j < n / 2 - i; j++)
				cout << ' ';
			cout << '*';
			for (int j = 0; j < i * 2 - 1; j++)
				cout << ' ';
			if (i != 0)
				cout << '*';
			cout << '\n';
		}
	}
}
