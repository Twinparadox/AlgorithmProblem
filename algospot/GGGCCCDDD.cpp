#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n, m, k;
	double sum = 0;
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
	{
		k = n / i;
		for (int j = n; j >= 0; j--)
		{
			sum += pow(k, j)*i;
//			sum += (pow(n, j) - pow(k, j));
		}
	}

	cout << sum;
	return 0;
}
