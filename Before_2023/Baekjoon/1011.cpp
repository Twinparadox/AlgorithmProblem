#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
	long long dist, w, dist2;
	int s, e, t;
	cin >> t;
	while (t--)
	{
		cin >> s >> e;
		dist = e - s;
		for (w = 1; w*w <= dist; w++);
		w--;

		dist2 = dist - w*w;
	    dist2 = (long long)ceil((double)dist2 / w);
		cout << w * 2 - 1 + dist2 << '\n';
	}
}
