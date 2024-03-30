#include <iostream>
#include <math.h>
#include <limits.h>
#include <vector>
using namespace std;
int init(vector<pair<int, int> > &a, vector<int> &tree, int node, int start, int end)
{
	if (start == end)
	{
		a[start].second = node;
		return tree[node] = a[start].first;
	}
	else
	{
		int cand1, cand2;
		cand1 = init(a, tree, node * 2, start, (start + end) / 2);
		cand2 = init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
		return tree[node] = cand1 < cand2 ? cand1 : cand2;
	}
}
void update(vector<pair<int, int> > &a, vector<int> &tree, int start)
{
	if (start % 2 == 1)
	{
		if (tree[start / 2] <= tree[start] && tree[start / 2] == tree[start - 1])
		{
			return;
		}
		else
		{
			tree[start / 2] = tree[start] < tree[start - 1] ? tree[start] : tree[start - 1];
			update(a, tree, start / 2);
		}
	}
	else
	{
		if (tree[start / 2] <= tree[start] && tree[start / 2] == tree[start + 1])
		{
			return;
		}
		else
		{
			tree[start / 2] = tree[start] < tree[start + 1] ? tree[start] : tree[start + 1];
			update(a, tree, start / 2);
		}
	}
}
int min(vector<int> &tree, int node, int start, int end, int left, int right)
{
	if (left <= start && end <= right)
	{
		return tree[node];
	}
	if (left > end || right < start)
	{
		return INT_MAX;
	}
	int cand1 = min(tree, node * 2, start, (start + end) / 2, left, right);
	int cand2 = min(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	return cand1 < cand2 ? cand1 : cand2;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	std::ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n;
	vector<pair<int, int> > a(n);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<int> tree(tree_size);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first;
		a[i].second = -1;
	}
	init(a, tree, 1, 0, n - 1);
	cin >> m;
	while (m--)
	{
		int t1, t2, t3;
		cin >> t1;
		if (t1 == 1)
		{
			int t2, t3;
			cin >> t2 >> t3;
			a[t2 - 1].first = t3;
			tree[a[t2 - 1].second] = t3;
			update(a, tree, a[t2 - 1].second);
		}
		else if (t1 == 2)
		{
			int t2, t3;
			cin >> t2 >> t3;
			cout << min(tree, 1, 0, n - 1, t2 - 1, t3 - 1) << '\n';
		}
	}
	return 0;
}