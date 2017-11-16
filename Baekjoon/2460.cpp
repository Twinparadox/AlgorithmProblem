#include <iostream>
using namespace std;
int main(void)
{
	int n, m;
	int sum = 0;
	int max = 0;

	for (int i = 0; i<10; i++)
	{
		cin >> n >> m;
		sum += (m - n);
		if (max<sum)
		{
			max = sum;
		}
	}
	cout << max;
	return 0;
}
