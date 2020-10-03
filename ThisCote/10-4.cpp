/*
�̰��� ���״�
Graph - Union-Find, Disjoint Set
�⺻ �ڵ� ����
+ �θ��带 �Ž��� �ö󰡾� �ϴ� �ð��� ���̴� ��� ���� ����
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int V, E;
vector<int> parent;
int findParent(int x)
{
	if (parent[x] != x)
		return parent[x] = findParent(parent[x]);
	return parent[x];
}
void unionParent(int a, int b)
{
	a = findParent(a);
	b = findParent(b);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}
int main(void)
{
	cin >> V >> E;
	parent.resize(V + 1, 0);

	for (int i = 1; i <= V; i++)
		parent[i] = i;

	int a, b;
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b;
		unionParent(a, b);
	}

	cout << "�� ���Ұ� ���� ����: \n";
	for (int i = 1; i <= V; i++)
		cout << findParent(i) << ' ';

	cout << "\n�θ����̺� : \n";
	for (int i = 1; i <= V; i++)
		cout << parent[i] << ' ';
}