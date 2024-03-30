#include <iostream>
using namespace std;
int main(void)
{
	int n, tmp, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		sum += tmp;
	}
	cout << sum - n + 1;
}
