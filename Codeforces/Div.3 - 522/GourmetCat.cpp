#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
	int a, b, c, bW, cW;
	int days[7] = { 1,2,3,1,3,2,1 };
	int week = 0, day = 0, max = 0;
	cin >> a >> b >> c;

	week = a / 3;
	bW = b / 2;
	cW = c / 2;

	if (week > bW)
		week = bW;
	if (week > cW)
		week = cW;

	a -= week * 3;
	b -= week * 2;
	c -= week * 2;

	for (int start = 0; start < 7; start++)
	{
		day = 0;
		int d[3] = { a,b,c };
		for (int i = 0; ; i++)
		{
			int idx = days[(start + i) % 7] - 1;
			if (d[idx] > 0)
				d[idx]--, day++;
			else
				break;
		}
		if (max < day)
			max = day;
	}

	cout << (week * 7) + max;
}