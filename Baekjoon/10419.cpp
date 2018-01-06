#include <iostream>
using namespace std;
int main(void)
{
	int t, cnt, d;
	cin >> t;
	while (t--)
	{
		cin >> d;
		for (cnt = 1; cnt + cnt*cnt <= d; cnt++);
		cout << cnt - 1 << '\n';
	}
}
