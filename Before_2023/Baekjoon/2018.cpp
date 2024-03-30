#include <iostream>
using namespace std;
int main(void)
{
	int n, cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (n == (i * j + (j - 1)*j / 2))
			{
				cnt++;
				break;
			}
			else if (n < (i*j + (j + 1)*j / 2))
				break;
		}
	}
	cout << cnt;
}