#include <iostream>
using namespace std;
int main(void)
{
	int n, sum = 5;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		sum = (sum + 3 * i + 1) % 45678;
	}
	cout << sum;
}
