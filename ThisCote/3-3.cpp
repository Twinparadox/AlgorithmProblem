/*
�̰��� ���״�
�׸��� - ����ī�����
�׳� ���� �� �Է� �ް�, �� �ٸ��� �ּڰ� ����� ��,
���� �ؿ����� ��� ���� �ּڰ� �� �ִ� �����ϸ� �Ǵ� ����
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int N, M, ans = 0, su;
	vector<int> arr;
	cin >> N >> M;

	arr.resize(N, 1e5);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> su;
			arr[i] = arr[i] < su ? arr[i] : su;
		}
		ans = ans < arr[i] ? arr[i] : ans;
	}

	cout << ans;
}