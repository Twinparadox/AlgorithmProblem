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
void update(vector<long long> &tree, int node, int start, int end, int index, long long diff)
{
	if (index < start || index > end)
		return;
	tree[node] = tree[node] + diff;
	if (start != end)
	{
		update(tree, node * 2, start, (start + end) / 2, index, diff);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}
long long sum(vector<long long> &tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[node];
	return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N, Q;
	cin >> N >> Q;
	vector<long long> arr(N);
	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h + 1));
	vector<long long> tree(tree_size);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	init(arr, tree, 1, 0, N - 1);
	while (Q--)
	{
		int x, y, a, b;
		cin >> x >> y >> a >> b;

		if (x < y)
			cout << sum(tree, 1, 0, N - 1, x - 1, y - 1) << '\n';
		else
			cout << sum(tree, 1, 0, N - 1, y - 1, x - 1) << '\n';

		a -= 1;
		long long diff = b - arr[a];
		arr[a] = b;
		update(tree, 1, 0, N - 1, a, diff);
	}
}