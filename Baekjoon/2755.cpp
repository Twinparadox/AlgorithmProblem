#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(void)
{
	string tmp, gr;
	int n, total = 0, tp;
	double grade = 0.0, g;
	cin >> n;
	while(n--)
	{
		cin >> tmp >> tp >> gr;
		total += tp;
		if (gr == "A+")
			g = 4.3;
		else if (gr == "A0")
			g = 4.0;
		else if (gr == "A-")
			g = 3.7;
		else if (gr == "B+")
			g = 3.3;
		else if (gr == "B0")
			g = 3.0;
		else if (gr == "B-")
			g = 2.7;
		else if (gr == "C+")
			g = 2.3;
		else if (gr == "C0")
			g = 2.0;
		else if (gr == "C-")
			g = 1.7;
		else if (gr == "D+")
			g = 1.3;
		else if (gr == "D0")
			g = 1.0;
		else if (gr == "D-")
			g = 0.7;
		else
			g = 0;
		grade += g*tp;
	}
	cout.precision(2);
	cout << fixed << floor((double)(grade / total) * 100 + 0.5) / 100;
}
