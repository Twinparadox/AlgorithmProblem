#include <iostream>
using namespace std;
int main(void)
{
	int n, f, cnt = 0, ans;
	cin >> n >> f;
	ans = n - (n % 100);
	for (; (ans + cnt) % f; cnt++);
	if (cnt < 10)
		cout << 0 << cnt;
	else
		cout << cnt;
}
