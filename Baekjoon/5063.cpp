#include <iostream>
using namespace std;
int main(void)
{
	int n, r, e, c;
	cin >> n;
	while (n--)
	{
		cin >> r >> e >> c;
		if (r == (e - c))
			cout << "does not matter\n";
		else if (r > (e - c))
			cout << "do not advertise\n";
		else
			cout << "advertise\n";
	}
}
