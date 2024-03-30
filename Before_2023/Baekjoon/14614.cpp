#include <iostream>
#include <string.h>
using namespace std;
int main(void)
{
	char c[101];
	int a, b, len, x;
	cin >> a >> b;
	cin >> c;
	len = strlen(c);
	x = (int)c[len - 1];
	if (x%2 == 1)
		cout << (a^b);
	else
		cout << a;
}
