/*
�̰��� ���״�
���� Ž�� - ������ �� �����
�⺻ ���� Ž�� ��������, �Ķ��Ʈ�� ��ġ ����
���� Ž������ ���ܱ� ũ�⸦ �����ذ��� ������ Ž��
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> a;
int cutting(int N, int size)
{
	int sum = 0;
	for (int i = 0; i < N; i++)
		if (a[i] - size >= 0)
			sum += a[i] - size;

	return sum;
}
int main(void)
{
	int N, M, mid, mi = 21e8, ma = 0, ans = 0, sub;

	cin >> N >> M;
	a.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
		ma = ma < a[i] ? a[i] : ma;
		mi = mi < a[i] ? mi : a[i];
	}

	while (mi <= ma)
	{
		mid = (mi + ma) / 2;

		sub = cutting(N, mid);
		if (sub == M)
		{
			ans = ans < mid ? mid : ans;
			break;
		}
		else if (sub > M)
		{
			ans = ans < mid ? mid : ans;
			mi = mid + 1;
		}
		else
			ma = mid - 1;
	}
	cout << ans;
}
