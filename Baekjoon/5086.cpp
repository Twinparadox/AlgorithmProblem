#include <iostream>
using namespace std;
int main(void)
{
	int n, m;
	while (1)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		if (m%n == 0)
			cout << "factor";
		else if (n%m == 0)
			cout << "multiple";
		else
			cout << "neither";
		cout << '\n';
	}
}
