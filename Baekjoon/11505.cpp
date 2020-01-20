#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
const int MOD = 1000000007;
long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end)
{
	if (start == end)
	{
		return tree[node] = a[start];
	}
	else
	{
		return tree[node] = (init(a, tree, node * 2, start, (start + end) / 2) * init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end)) % MOD;
	}
}
long long update(vector<long long> &tree, vector<long long>& a, int node, int start, int end, int index, long long prev, long long upd)
{
	if (index < start || index > end)
		return tree[node];
	else if (start == end)
		return tree[node] = upd;

	long long u1 = update(tree, a, node * 2, start, (start + end) / 2, index, prev, upd) % MOD;
	long long u2 = update(tree, a, node * 2 + 1, (start + end) / 2 + 1, end, index, prev, upd) % MOD;
	return tree[node] = (u1 * u2) % MOD;
}
long long multiply(vector<long long> &tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
	{
		return 1;
	}
	if (left <= start && end <= right)
	{
		return tree[node];
	}
	return (multiply(tree, node * 2, start, (start + end) / 2, left, right) * multiply(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right)) % MOD;
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
			int t2;
			long long t3;
			cin >> t2 >> t3;
			t2 -= 1;
			long long prev = a[t2];
			a[t2] = t3;
			update(tree, a, 1, 0, n - 1, t2, prev, t3);
		}
		else if (t1 == 2)
		{
			int t2, t3;
			cin >> t2 >> t3;
			cout << multiply(tree, 1, 0, n - 1, t2 - 1, t3 - 1) << '\n';
		}
	}
	return 0;
}