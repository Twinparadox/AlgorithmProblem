#include <iostream>
using namespace std;
bool IsHansu(int n)
{
	if (n < 100)
		return true;
	else if (n == 1000)
		return false;

	int cur;
	int dif;
	cur = n % 10, n /= 10;
	dif = (n % 10) - cur;
	if ((n / 10) - (n % 10) == dif)
		return true;
	else
		return false;
}
int main()
{
	int N;
	int cnt = 0;
	cin >> N;
	for (int i = 1; i <= N; i++)
		if (IsHansu(i))
			cnt++;
	cout << cnt << endl;
	return 0;
}