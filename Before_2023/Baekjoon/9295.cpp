#include <iostream>
using namespace std;
int main(void)
{
	int t, i = 1;
	cin >> t;
	while (i<=t)
	{
		int a, b;
		cin >> a >> b;
		cout << "Case " << i << ": " << a + b << "\n";
		i++;
	}
}
