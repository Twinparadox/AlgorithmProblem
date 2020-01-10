#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int N, ans = 0, zeros = 0, su;
	vector<int> minus;
	vector<int> plus;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> su;
		if (su < 0)
			minus.push_back(su);
		else if (su == 0)
			zeros++;
		else
			plus.push_back(su);
	}

	sort(minus.begin(), minus.end());
	sort(plus.begin(), plus.end());

	int sizeM = minus.size(), sizeP = plus.size();

	for (int i = 0; i < sizeM - 1; i += 2)
		ans += minus[i] * minus[i + 1];
	if (sizeM % 2)
	{
		if (zeros)
			zeros--;
		else
			ans += minus[sizeM - 1];
	}

	int i = sizeP - 1;
	for (; i >= 1; i -= 2)
	{
		if (plus[i] * plus[i - 1] < plus[i] + plus[i - 1])
			break;
		ans += plus[i] * plus[i - 1];
	}
	for (int j = 0; j <= i; j++)
		ans += plus[j];

	cout << ans;
}