#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int MAXD = 19;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int M;

	cin >> M;
	vector<vector<int> > table(M + 1, vector<int>(MAXD, 0));
	for (int i = 1; i <= M; i++)
		cin >> table[i][0];

	for (int i = 1; i <= MAXD; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			table[j][i] = table[table[j][i - 1]][i - 1];
		}
	}

	int Q, n, x;
	cin >> Q;
	while (Q--)
	{
		cin >> n >> x;
		for (int i = MAXD - 1; i >= 0; i--)
		{
			if (n >= 1 << i)
			{
				n -= 1 << i;
				x = table[x][i];
			}
		}

		cout << x << '\n';
	}
}