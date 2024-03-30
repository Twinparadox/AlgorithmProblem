#include <iostream>
using namespace std;
int main(void)
{
	int n;
	while (1)
	{
		cin >> n;
		if (n == 0)
			break;
		int arr[10] = { 0, }, tmp, sum, cnt = 0;
		tmp = n;
		while (tmp > 0)
		{
			arr[tmp % 10]++;
			tmp /= 10;
			cnt++;
		}
		sum = 1 + cnt + arr[0] * 4 + arr[1] * 2;
		for (int i = 2; i < 10; i++)
			sum += arr[i] * 3;
		cout << sum << '\n';
	}
}
