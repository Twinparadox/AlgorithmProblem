#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
	int m, n, i, arr[21] = { 0, };
	cin >> m >> n;
	for (i = 0; m >= n; i++)
	{
		arr[i] = m % n;
		m /= n;
	}
	arr[i] = m;

	for (int k = i; k >= 0; k--)
	{
		if (arr[k] >= 10)
		{
			switch (arr[k])
			{
			case 10:
				cout << 'A';
				break;
			case 11:
				cout << 'B';
				break;
			case 12:
				cout << 'C';
				break;
			case 13:
				cout << 'D';
				break;
			case 14:
				cout << 'E';
				break;
			case 15:
				cout << 'F';
				break;
			default:
				break;
			}
		}
		else
			cout << arr[k];
	}
}
