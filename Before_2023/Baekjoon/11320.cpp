#include <iostream>
using namespace std;
int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		int a, b, k;
		cin >> a >> b;
		k = (a * a) / (b * b);
		if ((a*a) % (b*b))
			k++;
		cout << k << '\n';
	}
}
