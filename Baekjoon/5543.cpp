#include <iostream>
using namespace std;
int main(void)
{
	int min1 = 2001, min2 = 2001, x;
	for (int i = 0; i < 3; i++)
	{
		cin >> x;
		min1 = min1 < x ? min1 : x;
	}
	for (int i = 0; i < 2; i++)
	{
		cin >> x;
		min2 = min2 < x ? min2 : x;
	}
	cout << min1 + min2 - 50;
}
