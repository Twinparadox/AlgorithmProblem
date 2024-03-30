#include <iostream>
using namespace std;
int main(void)
{
	int a, b, c, sub1, sub2;
	cin >> a >> b >> c;
	sub1 = b - a, sub2 = c - b;
	cout << (sub1 < sub2 ? sub2 : sub1) - 1;
}
