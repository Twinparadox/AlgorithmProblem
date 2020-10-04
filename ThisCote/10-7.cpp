/*
이것이 코테다
10강 팀 결성 - Union-Find
*/
#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<int> parent;
int findParent(int x)
{
	if (parent[x] != x)
		return parent[x] = findParent(parent[x]);
	return parent[x];
}
void unionParent(int x, int y)
{
	x = findParent(x);
	y = findParent(y);
	if (x < y)
		parent[y] = x;
	else
		parent[x] = y;
}
int main(void)
{
	cin >> N >> M;
	parent.resize(N + 1, 0);
	for (int i = 1; i <= N; i++)
		parent[i] = i;

	int op, x, y;
	for (int i = 0; i < M; i++)
	{
		cin >> op >> x >> y;
		if (!op)
		{
			unionParent(x, y);
		}
		else
		{
			if (findParent(x) == findParent(y))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}