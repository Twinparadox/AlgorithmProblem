/*
이것이 코테다
Graph - Union-Find, Disjoint Set
기본 코드 구현
+ 부모노드를 거슬러 올라가야 하는 시간을 줄이는 경로 압축 적용
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

	cout << "각 원소가 속한 집합: \n";
	for (int i = 1; i <= V; i++)
		cout << findParent(i) << ' ';

	cout << "\n부모테이블 : \n";
	for (int i = 1; i <= V; i++)
		cout << parent[i] << ' ';
}