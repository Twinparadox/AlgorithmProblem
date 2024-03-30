#include <iostream>
using namespace std;
int main(void)
{
	int n, m, k, max, restN, restM;
	cin >> n >> m >> k;
	max = (n / 2) < m ? (n / 2) : m;
	restN = n - max * 2, restM = m - max;
	if (restN + restM >= k)
		cout << max;
	else
	{
		if ((k - restN - restM) % 3 == 0)
			max -= (k - restN - restM) / 3;
		else
			max -= (k - restN - restM) / 3 + 1;
		cout << max;
	}
}
