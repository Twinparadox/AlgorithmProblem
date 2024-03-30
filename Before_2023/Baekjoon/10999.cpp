#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = a[start];
	else
		return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) + init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}
void update_lazy(vector<long long> &tree, vector<long long> &lazy, int node, int start, int end)
{
	if (lazy[node] != 0)
	{
		tree[node] += (end - start + 1)*lazy[node];
		if (start != end)
		{
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
void update(vector<long long> &tree, vector<long long> &lazy, int node, int start, int end, int left, int right, long long diff)
{
	update_lazy(tree, lazy, node, start, end);
	if (left > end || right < start)
		return;
	if (left <= start && end <= right)
	{
		tree[node] += (end - start + 1)*diff;
		if (start != end)
		{
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
		return;
	}
	update(tree, lazy, node * 2, start, (start + end) / 2, left, right, diff);
	update(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
long long sum(vector<long long> &tree, vector<long long> &lazy, int node, int start, int end, int left, int right)
{
	update_lazy(tree, lazy, node, start, end);
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[node];
	return sum(tree, lazy, node * 2, start, (start + end) / 2, left, right) + sum(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;
	vector<long long> a(n);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));

	vector<long long> tree(tree_size);
	vector<long long> lazy(tree_size);

	m += k;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	init(a, tree, 1, 0, n - 1);
	while (m--)
	{
		int t1, t2, t3;
		cin >> t1;
		if (t1 == 1)
		{
			long long v;
			cin >> t2 >> t3 >> v;
			update(tree, lazy, 1, 0, n - 1, t2 - 1, t3 - 1, v);
		}
		else if (t1 == 2)
		{
			int t2, t3;
			cin >> t2 >> t3;
			cout << sum(tree, lazy, 1, 0, n - 1, t2 - 1, t3 - 1) << '\n';
		}
	}
}