#include <iostream>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	if (n <= 5)
		cout << 0;
	else
		cout << (n / 2 - 2)*(n / 2 - 1) / 2;
}
