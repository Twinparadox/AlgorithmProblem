#include <iostream>
using namespace std;
long long gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}
int main(void)
{
	int t, n, arr[100];
	long long sum;
	cin >> t;
	while (t--)
	{
		sum = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (arr[i] > arr[j])
					sum += gcd(arr[i], arr[j]);
				else
					sum += gcd(arr[j], arr[i]);
			}
		}
		cout << sum << "\n";
	}
}
