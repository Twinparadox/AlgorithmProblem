#include <iostream>
using namespace std;
void hanoi(int n, int from, int temp, int to)
{
	if (n == 1)
		cout << from << " " << to << '\n';
	else
	{
		hanoi(n - 1, from, to, temp);
		cout << from << " " << to << '\n';
		hanoi(n - 1, temp, from, to);
	}
}
int main(void)
{
	int num, i, j, tmp, cnt = 0;
	char su[40], ctmp;
	cin >> num;
	su[0] = '1';
	for (int i = 1; i <= num; i++)
	{
		tmp = 0;
		for (j = cnt; j >= 0; j--)
		{
			tmp += (su[j] - '0') * 2;
			su[j] = tmp % 10 + '0';
			tmp /= 10;
		}
		if (tmp > 0)
		{
			ctmp = tmp + '0', cnt++;
			for (j = cnt; j >= 1; j--)
				su[j] = su[j - 1];
			su[0] = ctmp;
		}
	}
	su[cnt]--;

	for (int i = 0; i <= cnt; i++)
		cout << su[i];

	cout << endl;

	if (num <= 20)
		hanoi(num, 1, 2, 3);
}
