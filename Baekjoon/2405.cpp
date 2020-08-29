/* [G3] 2405 - �� ��, �� M */
/*
���� �����̱� �ϳ�, ���̵��� ���� ����
�ε��Ҽ��� ������ ����ؼ� �Ǽ� ������ ������� �ʾƾ� ��
����� ��� * 3�̱� ������, ��������� |2b - (a+c)|�� �ִ�ȭ�ϴ� ���� ��ǥ
�ش� ���� �ִ�ȭ�ϴ� ������, �ּڰ��̳� �ִ��� �����صΰ�
���� (b,c)�� (a,b)�� ���ذ��鼭 ������ ã���� �Ǵ� ����
*/
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int main(void)
{
	int N, ans = 0, tmp;
	vector<int> arr;

	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());
	for (int i = 1; i < N - 1; i++)
	{
		tmp = 2 * arr[i] - arr[0] - arr[i + 1];
		tmp = abs(tmp);
		ans = max(tmp, ans);

		tmp = 2 * arr[i] - arr[i - 1] - arr[N - 1];
		tmp = abs(tmp);
		ans = max(tmp, ans);
	}
	cout << ans;
}