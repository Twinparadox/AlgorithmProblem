#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	vector<int> Tri(302, 0);
	int T;
	cin >> T;

	for (int i = 1; i <= 301; i++)
		Tri[i] = Tri[i - 1] + i;
	while (T--)
	{
		int n;
		cin >> n;

		int sum = 0;
		for (int k = 1; k <= n; k++)
			sum += k * Tri[k + 1];

		cout << sum << '\n';
	}
}