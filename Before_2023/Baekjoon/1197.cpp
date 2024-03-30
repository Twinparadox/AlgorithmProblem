#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> sets;
struct Edge
{
	int u, v, w;
};
bool compare(const struct Edge a, const struct Edge b)
{
	return a.w < b.w;
}
int find(int a)
{
	if (sets[a] < 0)
		return a;
	return sets[a] = find(sets[a]);
}
bool merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b)
		return false;
	sets[b] = a;
	return true;
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<struct Edge> e(M, { -1,-1,0 });
	sets = vector<int>(N + 1, -1);
	for (int i = 0; i < M; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		e[i] = { u,v,w };
	}
	sort(e.begin(), e.end(), compare);

	int ans = 0, cnt = 0;
	for (int i = 0; i < M; i++)
	{
		if (merge(e[i].u, e[i].v))
		{
			ans += e[i].w;
			cnt++;
			if (cnt == N - 1)
				break;
		}
	}
	cout << ans;
}