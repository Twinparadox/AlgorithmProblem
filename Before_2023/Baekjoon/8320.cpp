#include <iostream>
using namespace std;
int main(void)
{
	int n, cnt = 0;
	cin >> n;
	for (int i = 1; i*i <= n; i++)
		cnt += n / i - i + 1;
	cout << cnt;
}
