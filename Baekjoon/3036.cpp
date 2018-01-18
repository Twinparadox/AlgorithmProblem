#include <iostream>
using namespace std;
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}
int main(void)
{
	int n, left, g;
	int arr[100];
	cin >> n >> left;
	for (int i = 0; i < n - 1; i++)
		cin >> arr[i];
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] > left)
			g = gcd(arr[i], left);
		else
			g = gcd(left, arr[i]);
		cout << left / g << "/" << arr[i] / g << '\n';
	}
}
