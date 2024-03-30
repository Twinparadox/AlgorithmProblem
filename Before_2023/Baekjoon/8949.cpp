#include <iostream>
using namespace std;
int main(void)
{
	int arr[10], a, b, size = 0;
	cin >> a >> b;
	while (a > 0 && b > 0)
	{
		arr[size++] = (a % 10) + (b % 10);
		a /= 10, b /= 10;
	}
	while (a > 0) arr[size++] = (a % 10), a /= 10;
	while (b > 0) arr[size++] = (b % 10), b /= 10;
	for (int i = size - 1; i >= 0; i--)
		cout << arr[i];
}
