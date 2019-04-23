#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int T;
	string origin[6] = { "Yakk","Doh","Seh","Ghar","Bang","Sheesh" };
	string combin[6] = { "Habb Yakk","Dobara","Dousa","Dorgy","Dabash","Dosh" };
	string except = "Sheesh Beesh";
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cout << "Case " << i << ": ";
		int a, b;
		cin >> a >> b;
		if (a == b)
		{
			cout << combin[a - 1];
		}
		else
		{
			if ((a == 5 && b == 6) || (a == 6 && b == 5))
				cout << except;
			else
			{
				if (a > b)
					cout << origin[a - 1] << ' ' << origin[b - 1];
				else
					cout << origin[b - 1] << ' ' << origin[a - 1];
			}
		}
		cout << '\n';
	}
}