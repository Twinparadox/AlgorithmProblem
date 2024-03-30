#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
	long long n;
	cin >> n;
	cout << (long long)(pow(2, n) + 1)*(long long)(pow(2, n) + 1);
}
