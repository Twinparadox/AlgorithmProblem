#include <iostream>
#include <math.h>
#include <limits.h>
#include <vector>
using namespace std;
int getMin(int x, int y) { return x < y ? x : y; }
int RMQ(vector<int> &tree, int ts, int te, int qs, int qe, int idx)
{
	if (qs <= ts && qe >= te)
		return tree[idx];
	if (te<qs || ts>qe)
		return INT_MAX;

	int mid = ts + (te - ts) / 2;
	int a = RMQ(tree, ts, mid, qs, qe, idx * 2 + 1);
	int b = RMQ(tree, mid + 1, te, qs, qe, idx * 2 + 2);
	return getMin(a, b);
}
int Query(vector<int> &tree, int n, int start, int end)
{
	if (start<0 || end>n - 1 || start > end)
		return -1;
	return RMQ(tree, 0, n - 1, start, end, 0);
}
int constructTree(vector<int> &arr, int start, int end, vector<int> &tree, int idx)
{
	if (start == end)
	{
		tree[idx] = arr[start];
		return arr[start];
	}
	else
	{
		int mid = start + (end - start) / 2;
		int a = constructTree(arr, start, mid, tree, idx * 2 + 1);
		int b = constructTree(arr, mid + 1, end, tree, idx * 2 + 2);
		tree[idx] = getMin(a, b);
		return tree[idx];
	}
}
vector<int> initTree(vector<int> &arr, int n)
{
	int height = (int)(ceil(log2(n)));
	int maxSize = 2 * (int)pow(2, height) - 1;
	vector<int> tree(maxSize);

	constructTree(arr, 0, n - 1, tree, 0);
	return tree;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, start, end;
	cin >> n >> m;
	vector<int> arr(n);
	vector<int> tree;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	tree = initTree(arr, n);
	for (int i = 0; i < m; i++)
	{
		cin >> start >> end;
		cout << Query(tree, n, start - 1, end - 1) << '\n';
	}
}