/*
[G5] 1446 - ������
DP�� Ǯ�� �Ǵ� ����
�����濡 ���� ������ ������/��������/��� �������� ������ ��,
DP ���̺��� �ϼ��ؾ� ��
���� ���ǿ��� '������'�� ���ٴ� ���� �����ؼ� dp[1] ~ dp[D]���� ���������� �ϼ��ϸ� ��
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct path
{
	int source;
	int dest;
	int cost;
};
bool compare(const struct path a, const struct path b)
{
	if (a.source < b.source)
		return true;
	else if (a.source == b.source)
	{
		if (a.dest < b.dest)
			return true;
		else if (a.dest == b.dest)
			return a.cost < b.cost;
		else
			return false;
	}
	else
		return false;
}
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int N, D;
	vector<struct path> arr;
	vector<int> cost;

	cin >> N >> D;
	arr.resize(N);
	cost.resize(D + 1, 0);

	for (int i = 0; i < N; i++)
		cin >> arr[i].source >> arr[i].dest >> arr[i].cost;
	for (int i = 0; i <= D; i++)
		cost[i] = i;

	sort(arr.begin(), arr.end(), compare);

	int idx = 0;
	for (int i = 0; i <= D && idx < N; i++)
	{
		if (i == arr[idx].source)
		{
			while (idx < N && i == arr[idx].source)
			{
				if (arr[idx].dest > D)
					idx++;

				int p1 = cost[arr[idx].source] + arr[idx].cost;
				int p2 = cost[arr[idx].dest];
				cost[arr[idx].dest] = min(p1, p2);

				for (int j = arr[idx].dest + 1; j <= D; j++)
					cost[j] = min(cost[j - 1] + 1, cost[j]);

				idx++;
			}
		}
	}

	cout << cost[D];
}