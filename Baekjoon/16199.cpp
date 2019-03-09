#include <iostream>
using namespace std;
int main(void)
{
	int by, bm, bd, cy, cm, cd;
	int iAge, cAge, yAge;
	cin >> by >> bm >> bd >> cy >> cm >> cd;

	cAge = yAge = cy - by + 1;

	if (cy == by)
		iAge = 0;
	else
	{
		iAge = cy - by;
		if (bm > cm)
			iAge--;
		else if (bm == cm && bd > cd)
			iAge--;
	}
	yAge--;
	cout << iAge << '\n' << cAge << '\n' << yAge;
}