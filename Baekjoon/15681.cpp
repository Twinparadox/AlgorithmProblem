/* [G5] 15681 - 트리와 쿼리 */
/*
Tree + DP(DFS)
문제 안에 풀이 방법이 자세히 기록되어 있음
*/
#include <iostream>
#include <vector>
using namespace std;
int R, N, Q;
vector<vector<int> > adj;
vector<bool> check;
vector<int> counts;
int dfs(int root)
{
	if (counts[root])
		return counts[root];

	counts[root] = 1;
	int size = adj[root].size();
	for (int i = 0; i < size; i++)
	{
		if (!check[adj[root][i]])
		{
			check[adj[root][i]] = true;
			counts[root] += dfs(adj[root][i]);
		}
	}
	return counts[root];
}
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	cin >> N >> R >> Q;
	adj.resize(N + 1, vector<int>());
	check.resize(N + 1, false);
	counts.resize(N + 1, 0);

	int u, v;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	check[R] = true;
	dfs(R);

	int node;
	for (int i = 0; i < Q; i++)
	{
		cin >> node;
		cout << counts[node] << '\n';
	}
}