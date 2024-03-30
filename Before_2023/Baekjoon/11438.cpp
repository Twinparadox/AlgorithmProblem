/* [P5] 11437 - LCA2 */
/*
LCA
가장 가까운 공통 조상
문제 풀이 방법에는 Segment Tree와 DP가 있으나, 풀이 방법은 DP
https://www.geeksforgeeks.org/lca-for-general-or-n-ary-trees-sparse-matrix-dp-approach-onlogn-ologn
해당 주소 참조
문제 조건이 조금 더 타이트해졌다는 것 외에 크게 다르지 않음
*/
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
const int MAXLEV = (int)floor(log2(1e5));
vector<int> depth;
vector<vector<int> > ancestor, graph;
int N, M;
void makeTree(int cur, int parent)
{
	depth[cur] = depth[parent] + 1;
	ancestor[cur][0] = parent;

	for (int i = 1; i <= MAXLEV; i++)
	{
		int other = ancestor[cur][i - 1];
		ancestor[cur][i] = ancestor[other][i - 1];
	}

	int size = graph[cur].size();
	for (int i = 0; i < size; i++)
	{
		int tmp = graph[cur][i];
		if (tmp != parent)
			makeTree(tmp, cur);
	}
}

int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N;

	ancestor.resize(N + 1, vector<int>(log2(5e4 + 1), 0));
	graph.resize(N + 1);
	depth.resize(N + 1, 0);

	depth[0] = -1;
	int u, v;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	makeTree(1, 0);

	cin >> M;
	while (M--)
	{
		cin >> u >> v;
		if (depth[u] != depth[v])
		{
			if (depth[u] > depth[v])
				swap(u, v);

			for (int i = MAXLEV; i >= 0; i--)
				if (depth[u] <= depth[ancestor[v][i]])
					v = ancestor[v][i];
		}

		int lca = u;
		if (u != v)
		{
			for (int i = MAXLEV; i >= 0; i--)
			{
				if (ancestor[u][i] != ancestor[v][i])
				{
					u = ancestor[u][i];
					v = ancestor[v][i];
				}
				lca = ancestor[u][i];
			}
		}

		cout << lca << '\n';
	}
}