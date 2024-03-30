#include <iostream>
using namespace std;
int main(void)
{
	int n, m, x, y, tmp;
	int arr[101];
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		arr[i] = i;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		tmp = arr[x];
		arr[x] = arr[y];
		arr[y] = tmp;
	}
	for (int i = 1; i <= n; i++)
		cout << arr[i] << ' ';
}
