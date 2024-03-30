#include <iostream>
using namespace std;
int main(void)
{
	long long n;
	cin >> n;
	if (((n - 1) % 5 + 1) == 2 || ((n - 1) % 5 + 1) == 5)
		cout << "CY";
	else
		cout << "SK";
}
