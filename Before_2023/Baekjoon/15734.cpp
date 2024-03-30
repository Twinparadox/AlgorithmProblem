#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
	int L, R, A, ans;
	cin >> L >> R >> A;
	if (L == R)
	{
		ans = L + R + (A / 2) * 2;
	}
	else
	{
		int sub = abs(L - R);
		if (sub >= A)
		{
			ans = L < R ? L : R;
			ans += A;
			ans *= 2;
		}
		else
		{
			ans = L < R ? R : L;
			A -= sub;
			ans *= 2;
			ans += (A / 2) * 2;
		}
	}
	cout << ans;
}