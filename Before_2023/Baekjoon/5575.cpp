#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
	int a[3][2][3], sum[3][2], tmp;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			sum[i][j] = 0;
			for (int k = 0; k < 3; k++)
			{
				cin >> a[i][j][k];
				sum[i][j] += pow(60, 2 - k)*a[i][j][k];
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		tmp = sum[i][1] - sum[i][0];
		cout << tmp / 3600 << " ";
		tmp %= 3600;
		cout << tmp / 60 << " ";
		tmp %= 60;
		cout << tmp << "\n";
	}
}
