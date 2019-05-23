#include <iostream>
using namespace std;
int main(void)
{
	int N, M, len = 0, tmp;
	int arr[4] = { 0 };
	cin >> N >> M;

	tmp = N;
	while (tmp >= 10)
	{
		arr[len++] = tmp % 10;
		tmp /= 10;
	}
	arr[len++] = tmp;

	if (len*N <= M)
	{
		for (int i = 0; i < N; i++)
			cout << N;
	}
	else
	{
		int cnt = M / len, remain = M % len;
		for (int i = 0; i < cnt; i++)
			cout << N;

		for (int i = 0; i < remain; i++)
			cout << arr[len - 1 - i];
	}
}