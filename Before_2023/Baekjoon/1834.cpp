#include <iostream>
using namespace std;
int main(void)
{
	long long n, sum = 0;
	cin >> n;
	for (long long i = 1; i < n; i++)
		sum += (n*i + i);
	cout << sum;
}
