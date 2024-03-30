#include <iostream>
using namespace std;
int main(void)
{
	long long n, m, size;
	cin >> n >> m;
	size = (n - m) < 0 ? (m - n) : (n - m);
	cout << size;
}
