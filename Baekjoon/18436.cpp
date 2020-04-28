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

	int N, M;
	cin >> N;
	vector<long long> evenarr(N, 0), oddarr(N, 0);

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		evenarr[i] = (num + 1) % 2;
		oddarr[i] = num % 2;
	}

	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h + 1));
	vector<long long> eventree(tree_size), oddtree(tree_size);
	init(evenarr, eventree, 1, 0, N - 1);
	init(oddarr, oddtree, 1, 0, N - 1);

	cin >> M;
	while (M--)
	{
		int op;
		cin >> op;
		if (op == 2)
		{
			int l, r;
			cin >> l >> r;
			cout << sum(eventree, 1, 0, N - 1, l - 1, r - 1) << '\n';
		}
		else if (op == 3)
		{
			int l, r;
			cin >> l >> r;
			cout << sum(oddtree, 1, 0, N - 1, l - 1, r - 1) << '\n';
		}
		else
		{
			int i, k;
			cin >> i >> k;
			i -= 1;
			if (k % 2 == 0 && oddarr[i] == 1)
			{
				evenarr[i] = 1, oddarr[i] = 0;
				update(eventree, 1, 0, N - 1, i, 1);
				update(oddtree, 1, 0, N - 1, i, -1);
			}
			else if (k % 2 == 1 && evenarr[i] == 1)
			{
				evenarr[i] = 0, oddarr[i] = 1;
				update(eventree, 1, 0, N - 1, i, -1);
				update(oddtree, 1, 0, N - 1, i, 1);
			}
		}
	}
}