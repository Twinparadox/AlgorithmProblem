#include <iostream>
using namespace std;
int main(void)
{
	long long s, k, sum = 1, tmp1, tmp2;
	cin >> s >> k;
	tmp1 = s / k;
	tmp2 = s - tmp1*k;
	for (int i = 1; i <= k - tmp2; i++)
		sum *= tmp1;
	for (int i = 1; i <= tmp2; i++)
		sum *= (tmp1 + 1);
	cout << sum;
}
