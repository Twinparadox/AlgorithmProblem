#include <iostream>
using namespace std;
long long n, max=0, arr[100001];
long long minH();
int main(void)
{
	long long height;
	int i, j;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	for (i = 1; i <= n; i++)
	{
		height = arr[i]; // ����1
		for (j = 1; j <= n - i + 1; j++)
		{
			// ���� ��
			if (height * j > max)
				max = height * j;

			// ����2�� �� ���� ���� ����
			if (height > arr[i + j])
				height = arr[i + j];

		}
		if (i == n)
			if (n*minH() > max)
				max=n*minH();
	}
	cout << max;
}
// ����2
long long minH()
{
	long long min = arr[0];
	int i;
	for (i = 0; i < n; i++)
		if (min > arr[i])
			min = arr[i];
	return min;
}