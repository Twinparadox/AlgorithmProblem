#include <iostream>
using namespace std;
int main(void)
{
	int n, m, t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		cout << "You get " << n / m << " piece(s) and your dad gets " << n%m << " piece(s).\n";
	}
}
