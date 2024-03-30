#include <iostream>
#include <math.h>
#include <limits.h>
#include <vector>
using namespace std;
int getMin(int x, int y) { return x < y ? x : y; }
int getMax(int x, int y) { return x > y ? x : y; }
int minQuery(vector<int> &tree, int ts, int te, int qs, int qe, int idx)
{
	if (qs <= ts && qe >= te)
		return tree[idx];
	if (te<qs || ts>qe)
		return INT_MAX;

	int mid = ts + (te - ts) / 2;
	int a = minQuery(tree, ts, mid, qs, qe, idx * 2 + 1);
	int b = minQuery(tree, mid + 1, te, qs, qe, idx * 2 + 2);
	return getMin(a, b);
}
int maxQuery(vector<int> &tree, int ts, int te, int qs, int qe, int idx)
{
	if (qs <= ts && qe >= te)
		return tree[idx];
	if (te<qs || ts>qe)
		return INT_MIN;

	int mid = ts + (te - ts) / 2;
	int a = maxQuery(tree, ts, mid, qs, qe, idx * 2 + 1);
	int b = maxQuery(tree, mid + 1, te, qs, qe, idx * 2 + 2);
	return getMax(a, b);
}
int Query(vector<int> &tree, int n, int start, int end, int q)
{
	if (q == 0) // MinQuery
	{
		if (start<0 || end>n - 1 || start > end)
			return -1;
		return minQuery(tree, 0, n - 1, start, end, 0);
	}
	else if (q == 1) // MaxQeury
	{
		if (start<0 || end>n - 1 || start > end)
			return -1;
		return maxQuery(tree, 0, n - 1, start, end, 0);
	}
}
int constructMinTree(vector<int> &arr, int start, int end, vector<int> &tree, int idx)
{
	if (start == end)
	{
		tree[idx] = arr[start];
		return arr[start];
	}
	else
	{
		int mid = start + (end - start) / 2;
		int a = constructMinTree(arr, start, mid, tree, idx * 2 + 1);
		int b = constructMinTree(arr, mid + 1, end, tree, idx * 2 + 2);
		tree[idx] = getMin(a, b);
		return tree[idx];
	}
}
int constructMaxTree(vector<int> &arr, int start, int end, vector<int> &tree, int idx)
{
	if (start == end)
	{
		tree[idx] = arr[start];
		return arr[start];
	}
	else
	{
		int mid = start + (end - start) / 2;
		int a = constructMaxTree(arr, start, mid, tree, idx * 2 + 1);
		int b = constructMaxTree(arr, mid + 1, end, tree, idx * 2 + 2);
		tree[idx] = getMax(a, b);
		return tree[idx];
	}
}
vector<int> initTree(vector<int> &arr, int n, int q)
{
	int height = (int)(ceil(log2(n)));
	int maxSize = 2 * (int)pow(2, height) - 1;
	vector<int> tree(maxSize);

	if (q == 0)
		constructMinTree(arr, 0, n - 1, tree, 0);
	else if (q == 1)
		constructMaxTree(arr, 0, n - 1, tree, 0);
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
	vector<int> mintree, maxtree;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	mintree = initTree(arr, n, 0);
	maxtree = initTree(arr, n, 1);
	for (int i = 0; i < m; i++)
	{
		cin >> start >> end;
		cout << Query(mintree, n, start - 1, end - 1, 0) << ' ' << Query(maxtree, n, start - 1, end - 1, 1) << '\n';
	}
}