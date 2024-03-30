#include <iostream>
using namespace std;
int main(void)
{
	int x[4], y[4], sumx = 0, sumy = 0;
	for (int i = 0; i < 4; i++)
	{
		cin >> x[i];
		sumx += x[i];
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> y[i];
		sumy += y[i];
	}
	cout << (sumx >= sumy ? sumx : sumy);
}
