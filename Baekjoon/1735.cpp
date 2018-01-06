#include <iostream>
using namespace std;
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		gcd(b, a%b);
}
int main(void)
{
	int a1, a2, b1, b2, lcm, sum, ki;
	cin >> a1 >> a2;
	cin >> b1 >> b2;
	
	if (a2 > b2)
		lcm = gcd(a2, b2);
	else
		lcm = gcd(b2, a2);
		
	lcm = a2*b2 / lcm;
	a1 = (lcm / a2)*a1, b1 = (lcm / b2)*b1;
	sum = a1 + b1;
	
	if (sum > lcm)
		ki = gcd(sum, lcm);
	else
		ki = gcd(lcm, sum);
	cout << sum / ki << ' ' << lcm / ki;
}
