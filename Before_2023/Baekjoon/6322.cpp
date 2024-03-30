#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
	int a, b, c, find;
	cout.precision(3);
	for(int i=1;;i++)
	{
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
			break;

		double pita;
		if (a == -1)
			pita = c * c - b * b;
		else if (b == -1)
			pita = c * c - a * a;
		else
			pita = a * a + b * b;


		cout << "Triangle #" << i << '\n';
		if (pita <= 0)
		{
			cout << "Impossible.\n\n";
			continue;
		}

		pita = sqrt(pita);
		if (a == -1)
		{
			if (pita + b <= c)
				cout << "Impossible.\n";
			else
				cout << fixed << "a = " << pita << '\n';
		}
		else if (b == -1)
		{
			if (a + pita <= c)
				cout << "Impossible.\n";
			else
				cout << fixed << "b = " << pita << '\n';
		}
		else
		{
			if (a + b <= pita)
				cout << "Impossible.\n";
			else
				cout << fixed << "c = " << pita << '\n';
		}
		cout << '\n';
	}
}