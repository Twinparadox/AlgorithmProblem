#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M;
	int s, e;
	vector<vector<int> > floyd;

	cin >> N >> M;
	floyd.resize(N + 1, vector<int>(N + 1, 0));
	for (int i = 0; i < M; i++)
	{
		cin >> s >> e;
		floyd[s][e] = 1;
	}

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (floyd[i][k] && floyd[k][j])
					floyd[i][j] = 1;

	for (int i = 1; i <= N; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= N; j++)
		{
			if (i == j)
				continue;
			if (!floyd[i][j] && !floyd[j][i])
				cnt++;
		}
		cout << cnt << '\n';
	}
}