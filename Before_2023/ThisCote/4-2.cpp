/*
�̰��� ���״�
���� - �ð�
0 ~ 86399�� ���� 3�� ���ڰ� ������� �� üũ
�׳� ���� Ž��
*/
#include <iostream>
using namespace std;
bool divide(int su)
{
	if (su / 10 == 3)
		return true;
	else if (su % 10 == 3)
		return true;
	return false;
}
int main(void)
{
	int h, m, s, lapse = 0, n, cnt = 0;
	const int hour = 3600, minute = 60;

	cin >> n;
	for (; lapse < hour * (n + 1); lapse++)
	{
		h = lapse / hour;
		m = (lapse - h * hour) / minute;
		s = lapse % minute;
		bool flag = false;

		flag = flag || divide(h);
		flag = flag || divide(m);
		flag = flag || divide(s);
		if (flag)
			cnt++;
	}
	cout << cnt;
}