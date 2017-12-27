#include <iostream>
using namespace std;
int main(void)
{
	int q[5] = { 0, }, n, x, y;
	cin >> n;
	while (n--)
	{
		cin >> x >> y;
		if (x > 0 && y > 0)
			q[1]++;
		else if (x < 0 && y>0)
			q[2]++;
		else if (x < 0 && y < 0)
			q[3]++;
		else if (x > 0 && y < 0)
			q[4]++;
		else if (x == 0 || y == 0)
			q[0]++;
	}
	for (int i = 1; i <= 4; i++)
		cout << "Q" << i << ": " << q[i] << '\n';
	cout << "AXIS: " << q[0];
}
