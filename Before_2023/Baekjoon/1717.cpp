#include <iostream>
#include <vector>
using namespace std;
vector<int> parent;
int Find(int x)
{
	if (x == parent[x])
		return x;
	else
	{
		int y = Find(parent[x]);
		parent[x] = y;
		return y;
	}

}
void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	parent[y] = x;
}
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	parent = vector<int>(N + 1, 0);
	for (int i = 0; i <= N; i++)
		parent[i] = i;

	int op, a, b;
	while (M--)
	{
		cin >> op >> a >> b;
		if (op == 0)
			Union(a, b);
		else
		{
			int ap = Find(a);
			int bp = Find(b);

			if (ap == bp)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}