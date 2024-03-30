#include <iostream>
using namespace std;
int main(void)
{
	int n, cnt = 1;
	cin >> n;
	while (n != 1)
	{
		if (n % 2 == 0)
			n /= 2, cnt++;
		else
			n = n * 3 + 1, cnt++;
	}
	cout << cnt;
}
