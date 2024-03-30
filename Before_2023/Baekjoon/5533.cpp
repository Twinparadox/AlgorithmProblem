#include <iostream>
using namespace std;
int main(void)
{
	int n, arr[200][3], cnt[101][3] = { 0, }, sum[200] = { 0, };
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			cin >> arr[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			cnt[arr[i][j]][j]++;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			if (cnt[arr[i][j]][j] == 1)
				sum[i] += arr[i][j];
	for (int i = 0; i < n; i++)
		cout << sum[i] << "\n";
}
