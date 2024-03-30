/*
[G5] 10216 - Count Circle Groups
DFS or BFS, �׸��� Ž��, ������
���� �� ������ �Ÿ�, ���� ������ ����ؾ� ��
���� Ǯ�̴� ��� �� ������ ���� ���ϴ� ��� ������ ã�� �����
*/
#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
#include <vector>
using namespace std;
struct station
{
	int x, y, r, g;
};
vector<struct station> arr;
void bfs(int size, int gId, int start)
{
	vector<int> check(size, false);
	queue<int> q;
	q.push(start);

	arr[start].g = gId;
	while (!q.empty())
	{
		int idx = q.front();
		q.pop();

		if (!check[idx])
		{
			check[idx] = true;
			for (int i = 0; i < size; i++)
			{
				if (idx == i || arr[i].g != -1 || check[i])
					continue;

				int dist = (arr[idx].x - arr[i].x) * (arr[idx].x - arr[i].x) + (arr[idx].y - arr[i].y) * (arr[idx].y - arr[i].y);
				int peri = (arr[idx].r + arr[i].r) * (arr[idx].r + arr[i].r);

				if (dist <= peri)
				{
					arr[i].g = gId;
					q.push(i);
				}
			}
		}
	}
}
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int T, N;

	cin >> T;
	while (T--)
	{
		int groups = 0;
		cin >> N;

		arr.resize(N);
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i].x >> arr[i].y >> arr[i].r;
			arr[i].g = -1;
		}

		for (int i = 0; i < N; i++)
		{
			if (arr[i].g == -1)
			{
				groups++;
				bfs(N, groups, i);
			}
		}

		cout << groups << '\n';
		arr.clear();
	}
}