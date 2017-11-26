#include <iostream>
using namespace std;
int main(void)
{
	int n, t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			if (i > 1 && i < n)
			{
				cout << "#";
				for (int j = 2; j <= n-1; j++)
					cout << "J";
				cout << "#";
			}
			else
				for (int j = 1; j <= n; j++)
					cout << "#";
			cout << '\n';
		}
		cout<<'\n';
	}
}
