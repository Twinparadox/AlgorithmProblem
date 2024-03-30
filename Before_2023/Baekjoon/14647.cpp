#include <iostream>
using namespace std;
int check(int n)
{
	int cnt = 0;
	while (n)
	{
		if (n % 10 == 9)
			cnt++;
		n /= 10;
	}
	return cnt;
}
int main(void)
{
	int n, m, arr[501][501];
	int col[501] = { 0, }, row[501] = { 0, }, sum = 0, k, max = 0, idx;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> arr[i][j];
			k = check(arr[i][j]);
			col[j] += k, row[i] += k;
		}
	}
	for (int i = 1; i <= n; i++)
		if (max < row[i])
			max = row[i], idx = i;
	for (int i = 1; i <= m; i++)
		if (max < col[i])
			max = col[i], idx = -i;

	if (idx > 0)
	{
		for (int i = 1; i <= n; i++)
			if (i != idx)
				sum += row[i];
	}
	else
	{
		for (int i = 1; i <= m; i++)
			if (i != -idx)
				sum += col[i];
	}
	cout << sum;
}
