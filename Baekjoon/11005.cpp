#include <iostream>
#include <math.h>
#include <string>
using namespace std;
int main(void)
{
	int N, B;
	string ans = "";
	cin >> N >> B;
	while (N)
	{
		int div = N % B;
		if (div >= 10)
			ans = (char)('A' + div - 10) + ans;
		else
			ans = to_string(div) + ans;
		N /= B;
	}
	cout << ans;
}