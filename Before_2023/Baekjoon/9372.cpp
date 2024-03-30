#include <iostream>
#include <vector>
using namespace std;
int N, M;
struct Edge
{
	int u, v;
};
vector<struct Edge> edges;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		edges.resize(M);
		for (int i = 0; i < M; i++)
			cin >> edges[i].u >> edges[i].v;
		cout << N - 1 << '\n';
	}
}