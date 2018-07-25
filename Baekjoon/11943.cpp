#include <iostream>
using namespace std;
int main(void)
{
	int a, b, c, d, ans1, ans2;
	cin >> a >> b >> c >> d;
	ans1 = a + d;
	ans2 = b + c;
	cout << (ans1 < ans2 ? ans1 : ans2);
}
