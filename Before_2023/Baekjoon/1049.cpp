#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
	int n, m, sum = 0;
	int package[50], piece[50];
	bool cheap = false;

	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> package[i] >> piece[i];

	sort(package, package + m);
	sort(piece, piece + m);

	if ((double)package[0] / 6 < piece[0])
		cheap = true;
	if (cheap)
	{
		sum += n / 6 * package[0];
		n %= 6;
		if (n*piece[0] > package[0])
			sum += package[0];
		else
			sum += piece[0] * n;
	}
	else
	{
		sum = n * piece[0];
	}
	cout << sum;
}