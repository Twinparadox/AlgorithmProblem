#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
	double r, w, l, i = 1;
	while (1)
	{
		cin >> r;
		if (r == 0)
			break;
		cin >> w >> l;
		if (sqrt(w*w + l*l) <= 2*r)
			cout << "Pizza " << i << " fits on the table.\n";
		else
			cout << "Pizza " << i << " does not fit on the table.\n";
		i++;
	}
}
