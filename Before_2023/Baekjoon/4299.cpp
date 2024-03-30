#include <iostream>
using namespace std;
int main(void)
{
	int a, b, home, away;
	cin >> a >> b;
	home = (a + b) / 2;
	away = (a - b) / 2;
	if ((home < 0 || away < 0) || (home + away != a))
		cout << -1;
	else
		cout << home << ' ' << away;
}
