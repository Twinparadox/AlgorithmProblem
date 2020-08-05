/* [S2] 11725 - 트리의 부모 찾기 */
/*
Adjacent List로 연결 정보 기록 후,
Tree의 Root인 1번 Node로부터 Tree를 구성해나가는 탐색 실시
BFS, DFS 모두 사용 가능
두 번 체크하지 않도록 체크 필요
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