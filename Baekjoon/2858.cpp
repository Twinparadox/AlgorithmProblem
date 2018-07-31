#include <iostream>
using namespace std;
int main(void)
{
	int r, b, sum;
	int sw, sl, w, l;
	cin >> r >> b;

	for (l = 1;; l++)
	{
		if (b%l == 0)
			w = b / l;
		sum = w * 2 + l * 2 + 4;
		if (sum == r)
		{
			if (w > l)
				cout << w + 2 << ' ' << l + 2;
			else
				cout << l + 2 << ' ' << w + 2;
			break;
		}
	}
}
