#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
	int t, a[3];
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> a[j];
		sort(a, a + 3);
		if(a[2]>=a[0]+a[1])
			cout << "Case #" << i << ": invalid!\n";
		else if (a[0] == a[1] && a[1] == a[2])
			cout << "Case #" << i << ": equilateral\n";
		else if (a[0] == a[1] || a[1] == a[2])
			cout << "Case #" << i << ": isosceles\n";
		else
			cout << "Case #" << i << ": scalene\n";
	}
}
