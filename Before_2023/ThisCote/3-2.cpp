/*
�̰��� ���״�
�׸��� - ū ���� ��Ģ
�������� �����ϰ� arr[N-1]�� K�� ���ϰ� arr[N-2]�� �� �� ���ϰ�,
�ٽ� arr[N-1]�� K�� ���ϴ� ������ Ǯ��
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int N, M, K;
	long long ans = 0;
	vector<int> arr;

	cin >> N >> M >> K;
	arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());

	for (int i = 0, cnt = 1; i < M; i++)
	{
		if (cnt % K == 0)
			cnt = 1, ans += arr[N - 2];
		else
			ans += arr[N - 1], cnt++;
	}

	cout << ans;
}