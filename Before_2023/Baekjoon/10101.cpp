#include <iostream>
using namespace std;
int main(void)
{
	int a, b, c;
	cin >> a >> b >> c;
	if (a + b + c != 180)
	{
		cout << "Error";
		return 0;
	}
	if (a == b && b == c)
		cout << "Equilateral";
	else if (a != b && b != c && a != c)
		cout << "Scalene";
	else
		cout << "Isosceles";
}
