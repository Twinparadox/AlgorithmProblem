#include <iostream>
using namespace std;
int main(void)
{
	int v, e, t;
	cin >> t;
	while (t--)
	{
		cin >> v >> e;
		cout << e - v + 2 << "\n";
	}
}
