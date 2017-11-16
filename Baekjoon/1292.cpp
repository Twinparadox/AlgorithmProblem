#include <iostream>
using namespace std;
int main(void)
{
	int a, b, size = 0, arr[1001];
	long long sum = 0;
	cin >> a >> b;
	for (int i = 1; i <= b; i++)
	{
		for (int j = 0; j <= size && (j + size*(size + 1) / 2) < 1000; j++)
			arr[j + size*(size + 1) / 2] = i;
		size++;
	}
	for (int i = a - 1; i <= b - 1; i++)
		sum += arr[i];
	cout << sum;
}
