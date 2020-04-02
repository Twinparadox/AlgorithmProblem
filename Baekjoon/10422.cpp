#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int T, L;
	vector<long long> arr(2501, 0);
	const long long MOD = 1e9 + 7;

	cin >> T;
	arr[0] = 1;
	for (int i = 0; i < 2500; i++)
		for (int j = 0; j <= i; j++)
			arr[i + 1] = (arr[i + 1] + arr[j] * arr[i - j]) % MOD;

	while (T--)
	{
		cin >> L;
		if (L % 2 == 1)
			cout << 0;
		else
			cout << arr[L / 2];
		cout << '\n';
	}
}