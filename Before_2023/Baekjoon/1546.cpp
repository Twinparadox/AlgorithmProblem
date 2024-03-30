#include <iostream>
using namespace std;
int main(void)
{
	int n, max = 0;
	double arr[1000], aver = 0.0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		max = max < arr[i] ? arr[i] : max;
	}
	for (int i = 0; i < n; i++)
	{
		arr[i] = (double)arr[i] / (double)max * 100;
		aver += arr[i];
	}
	cout.precision(2);
	cout << fixed << (double)aver / (double)n;
}
