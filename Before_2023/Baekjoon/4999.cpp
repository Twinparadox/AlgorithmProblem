#include <iostream>
#include <string.h>
using namespace std;
int main(void)
{
	char x[1001], y[1001];
	int xlen, ylen;
	cin >> x;
	cin >> y;
	xlen = strlen(x), ylen = strlen(y);
	if (ylen > xlen)
		cout << "no";
	else
		cout << "go";
}
