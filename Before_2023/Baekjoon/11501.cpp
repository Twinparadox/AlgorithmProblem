// ��� �Ⱓ�� ������ �˰� ����
// Ư�� ���������� ����� ���ؼ��� ��� �Ĵ� �۾��� �����ؾ� ��
// �ڿ������� ������ �ִ��� �����س����鼭 �����ϸ� ��
// �ִ�ġ���� �����ϴ� ������ ��Ÿ�� ������, ���Ϳ� (�ִ��ְ� - �ش� ���� �ְ�)�� �����ָ� ������ ��
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int N, T;
	cin >> T;
	while (T--)
	{
		long long ans = 0;
		cin >> N;
		vector<long long> arr(N);
		for (int i = 0; i < N; i++)
			cin >> arr[i];

		long long localMax = arr[N - 1];
		for (int i = N - 2; i >= 0; i--)
		{
			if (arr[i] > localMax)
				localMax = arr[i];

			else if (arr[i] < localMax)
				ans += localMax - arr[i];
		}
		cout << ans << '\n';
	}
}