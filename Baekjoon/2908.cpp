#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
	const int SIZE = 3;
	char arr1[4], arr2[4];
	int ar1 = 0, ar2 = 0;
	bool first = false;
	cin >> arr1;
	cin >> arr2;
	for (int i = SIZE-1; i>=0; i--)
	{
		ar1 += (arr1[i] - '0')*pow(10, i);
		ar2 += (arr2[i] - '0')*pow(10, i);
	}
	cout << (ar1 > ar2 ? ar1 : ar2);
	return 0;
}
