#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
	int cnt = 0, n;
	cin >> n;
	for (int i = 1; i <= 500; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (pow(i, 2) - pow(j, 2) == n)
			{
				cnt++;
				break;
			}
		}
	}
	cout << cnt;
}
