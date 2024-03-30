#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	vector<int> multiple;
	vector<int> check;
	int N, ans = 0, subAns = 0, size;
	cin >> N;

	size = N / 3;
	int k = size - 1, r = size - 3;
	if (r < 0)
		ans = 0;
	else if (r == 0)
		ans = 1;
	else
	{
		int sub1 = 1, sub2 = 1;
		for (int i = 2; i <= k - r; i++)
			sub2 *= i;
		for (int j = k; j > r; j--)
			sub1 *= j;

		ans = sub1 / sub2;
	}
	cout << ans;
}