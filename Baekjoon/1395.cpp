#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
long long init(vector<long long>& a, vector<long long>& tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = a[start];
	else
		return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) + init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}
void update_lazy(vector<long long>& tree, vector<long long>& lazy, int node, int start, int end)
{
	if (lazy[node] != 0)
	{
		tree[node] = (end - start + 1) - tree[node];
		if (start != end)
		{
			lazy[node * 2] ^= 1;
			lazy[node * 2 + 1] ^= 1;
		}
		lazy[node] = 0;
	}
}
void update(vector<long long>& tree, vector<long long>& lazy, int node, int start, int end, int left, int right)
{
	update_lazy(tree, lazy, node, start, end);
	if (left > end || right < start)
		return;
	if (left <= start && end <= right)
	{
		lazy[node] ^= 1;
		update_lazy(tree, lazy, node, start, end);
		return;
	}
	update(tree, lazy, node * 2, start, (start + end) / 2, left, right);
	update(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
long long sum(vector<long long>& tree, vector<long long>& lazy, int node, int start, int end, int left, int right)
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

	int N, M;
	cin >> N >> M;
	vector<long long> a(N, 0);
	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h + 1));

	vector<long long> tree(tree_size);
	vector<long long> lazy(tree_size);

	init(a, tree, 1, 0, N - 1);
	while (M--)
	{
		int t1, t2, t3;
		cin >> t1;
		if (t1 == 0)
		{
			cin >> t2 >> t3;
			update(tree, lazy, 1, 0, N - 1, t2 - 1, t3 - 1);
		}
		else if (t1 == 1)
		{
			int t2, t3;
			cin >> t2 >> t3;
			cout << sum(tree, lazy, 1, 0, N - 1, t2 - 1, t3 - 1) << '\n';
		}
	}
}