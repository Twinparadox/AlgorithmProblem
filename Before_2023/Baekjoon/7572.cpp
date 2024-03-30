#include <iostream>
using namespace std;
int main(void)
{
	int n, gan, izi;
	cin >> n;
	gan = n % 12, izi = n % 10;
	cout << (char)('A' + (gan + 8) % 12) << (izi + 6) % 10;
}
