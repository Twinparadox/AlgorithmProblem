/* [G4] 2109 - ��ȸ���� */
/*
Greedy Algorithm
������ �ٽ���, '���� �� � ��¥��' ������ �� �ִ� �ǹ�
����, 3�� �̳���� �ϴ� ���� 1������ �����ص� ��� ���ٴ� �ǹ�
��¥�� �Ųٷ� �����ؼ�, ���� ������ �� �������� Ž���ذ��� �ִ��� ���� ���� ���� ���� �ٽ�

������ �������� �� ��, 20�������� 1�������� �������� Ž��
�� �������� ���� ������ ���� ���� ������ ���� ���, �ִ� ���� �־���� ������ ���� Ȱ��
�ִ� ���� ��� �ִ� �������� '��� ���� �� ����'��

1. � ���� �������� ��� ������ ���� ��, �ִ� ������ �ϳ� �����ͼ� ���� ��ġ
2. � ���� �������� ��� ������ �ִ� ���, �ִ� ���� ���ؼ� �� �� ū ���� ��ġ�ϰ�, �������� �ִ� ���� ��� �߰�
*/
#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(void)
{
	int N, d, p, ans = 0, curIdx = 0, cur = 0, maxD = 0;
	vector<vector<int> > days;
	priority_queue<int, vector<int>, less<int> > pq;
	cin >> N;

	days.resize(1e4 + 1);
	for (int i = 0; i < N; i++)
	{
		cin >> p >> d;
		days[d].emplace_back(p);
		maxD = max(maxD, d);
	}
	for (int i = maxD; i >= 1; i--)
	{
		int size = days[i].size();
		if (size)
		{
			sort(days[i].begin(), days[i].end(), greater<int>());
			if (!pq.empty())
			{
				if (pq.top() > days[i][0])
				{
					ans += pq.top();
					pq.pop();
					for (int j = 0; j < size; j++)
						pq.push(days[i][j]);
				}
				else
				{
					ans += days[i][0];
					for (int j = 1; j < size; j++)
						pq.push(days[i][j]);
				}
			}
			else
			{
				ans += days[i][0];
				for (int j = 1; j < size; j++)
					pq.push(days[i][j]);
			}
		}
		else if (!pq.empty())
		{
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans;
}