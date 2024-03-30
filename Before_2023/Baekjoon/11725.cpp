/* [S2] 11725 - Ʈ���� �θ� ã�� */
/*
Adjacent List�� ���� ���� ��� ��,
Tree�� Root�� 1�� Node�κ��� Tree�� �����س����� Ž�� �ǽ�
BFS, DFS ��� ��� ����
�� �� üũ���� �ʵ��� üũ �ʿ�
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int> > tree;
vector<int> parent;
vector<bool> check;
void bfs(int root)
{
	queue<int> q;
	q.push(root);
	check[root] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		int size = tree[cur].size();
		for (int i = 0; i < size; i++)
		{
			int next = tree[cur][i];
			if (!check[next])
			{
				q.push(next);
				parent[next] = cur;
				check[next] = true;
			}
		}
	}
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	tree.resize(N + 1, vector<int>());
	parent.resize(N + 1, 0);
	check.resize(N + 1, 0);

	for (int i = 0; i < N - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	bfs(1);

	for (int i = 2; i <= N; i++)
		cout << parent[i] << '\n';
}