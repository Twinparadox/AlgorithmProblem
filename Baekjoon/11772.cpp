#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
	int n, arr[10], sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sum += pow((int)(arr[i] / 10), arr[i] % 10);
	}
	cout << sum;
}
