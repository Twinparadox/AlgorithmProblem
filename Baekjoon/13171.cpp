#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	unsigned long long A, X, K, ans = 1;
	int tmp = 0, bin;
	const int mod = 1E9 + 7;
	vector<unsigned long long> arr(65, 0);

	cin >> A >> X;
	arr[1] = A;
	K = X;

	vector<int> sub;
	while (K)
	{
		tmp++;
		sub.push_back(K % 2);
		K /= 2;
	}
	if (K)
		sub.push_back(K);
	bin = tmp;

	for (int i = 2; i <= bin; i++)
		arr[i] = ((arr[i - 1] % mod)*(arr[i - 1] % mod)) % mod;

	int size = sub.size();
	for (int i = 0; i < size; i++)
		if (sub[i])
			ans = (ans*arr[i + 1]) % mod;

	cout << ans;
}