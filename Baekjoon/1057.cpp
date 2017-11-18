#include <iostream>
using namespace std;
int main(void)
{
	int n, a, b, i;
	cin >> n >> a >> b;
	a--, b--;
	for (i = 0; a - b != 0; i++)
		a /= 2, b /= 2;
	cout << i;
}
