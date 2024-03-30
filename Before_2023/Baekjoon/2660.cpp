#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	const int INF = 1e7;
	int N, ans = INF;
	vector<vector<int> > rel;
	vector<int> cand;

	cin >> N;
	rel.resize(N + 1, vector<int>(N + 1, INF));
	cand.resize(N + 1, INF);

	int u, v;
	while (1)
	{
		cin >> u >> v;
		if (u == -1 && v == -1)
			break;
		rel[u][v] = rel[v][u] = 1;
	}

	for (int i = 0; i <= N; i++)
		rel[i][i] = 0;

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (rel[i][k] + rel[k][j] < rel[i][j])
					rel[i][j] = rel[i][k] + rel[k][j];

	for (int i = 1; i <= N; i++)
	{
		int maxRel = 0;
		for (int j = 1; j <= N; j++)
			maxRel = rel[i][j] < maxRel ? maxRel : rel[i][j];
		cand[i] = maxRel;
		ans = ans < maxRel ? ans : maxRel;
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++)
		if (ans == cand[i])
			cnt++;

	cout << ans << ' ' << cnt << '\n';
	for (int i = 1; i <= N; i++)
		if (ans == cand[i])
			cout << i << ' ';
}