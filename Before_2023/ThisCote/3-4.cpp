/*
�̰��� ���״�
�׸��� - 1�� �ɶ�����
� ���� K�� ������ �������� ������ ������ ������ ������ ����
������ �������� ������
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int N, K, cnt = 0;
	cin >> N >> K;

	while (N > 1)
	{
		if (N % K)
		{
			int sub = N % K;
			N -= sub;
			cnt += sub;
		}
		else
			N /= K, cnt++;
	}
	cout << cnt;
}