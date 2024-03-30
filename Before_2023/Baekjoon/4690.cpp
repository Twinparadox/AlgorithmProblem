#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
	for (int a = 6; a <= 100; a++)
		for (int b = 2; b < a; b++)
			for (int c = b + 1; c <= 99; c++)
				for (int d = c + 1; d <= 100; d++)
					if (a*a*a == (b*b*b + c * c*c + d * d*d))
						cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")\n";
}